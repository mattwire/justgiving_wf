<?php
/**
 * @file
 * JustGiving Helper Class.
 */

libraries_load('justgiving');
use \JustGivingClient as jg;

class JustGiving {
  public $settings = array();
  public $forms = array();
  public $client;
  public $session;

  /**
   * Implements a custom debug.
   */
  public function debug($data, $output = TRUE) {
    if ($output) {
      debug($data);
    }
  }

  /**
   * Constructor Function.
   *
   * Function to build the session and set up the PHP SDK for use
   */
  public function __construct() {
    // Reference session varibales in our class
    $this->session = &$_SESSION['jg'];

    if (!isset($_SESSION)) {
      drupal_session_start();
    }
    libraries_load('justgiving');

    // debug($this->session);
    $this->getSettings();
    $this->client = new jg\JustGivingClient($this->settings['environment'], $this->settings['api-key'], 1);
  }

  /**
   * Destructor Function.
   *
   * In case this is fired reassign everything back into session for use later.
   */
  public function __destruct() {
    // debug($this->session);
    // Assign session variable back into $_SESSION global.
    $_SESSION['jg'] = $this->session;
    // debug($_SESSION);
  }

  /**
   * Settings Function.
   *
   * Pull the variables once from database and assign to class variables.
   */
  public function getSettings() {
    $this->settings = array(
      'api-key' => variable_get('justgiving_api_key'),
      'environment' => variable_get('justgiving_environment'),
    );
    switch ($this->settings['environment']) {
      case 'sandbox':
        $this->settings['environment'] = 'https://api.sandbox.justgiving.com/';
        break;
      case 'live':
        $this->settings['environment'] = 'https://api.justgiving.com/';
        break;
    }
    $this->forms = array(
      'page' => variable_get('justgiving_node_page_form'),
    );
  }

  /**
   * Custom JustGiving function for creating accounts.
   *
   * @return: Returns the response, or an error message.
   */
  public function accounts($type = 'list', $data = array()) {
    if ($this->settings['api-key'] && !empty($data)) {
      switch ($type) {
        case 'create':
          return $this->client->Account->CreateV2($data);
        case 'list':
          // TODO: Will list pages attached to said account.
          break;
      }
    } else {
      return array(
        'result' => FALSE,
        'message' => 'Cannot complete request',
      );
    }
  }

  /**
   * Custom JustGiving function for creating pages.
   *
   * @return: Returns either the response or an error message.
   */
  public function pages($type = 'list', $auth = array(), $data = array()) {
    // debug($data);
    if ($this->settings['api-key'] && !empty($data)) {
      switch ($type) {
        case 'create':
          // Re-invoke the client with Auth details to create a page.
          $this->client = new jg\JustGivingClient($this->settings['environment'], $this->settings['api-key'], 1, $auth['username'], $auth['password']);
          $page = new jg\RegisterPageRequest();
          foreach ($data as $key => $value) {
            if (is_array($value)) {
              foreach ($value as $keysub => $valuesub) {
                $page->$key->$keysub = $valuesub;
              }
            } else {
              $page->$key = $value;
            }
          }
          $response = $this->client->Page->CreateV2($page);
          return $response;
          break;

        case 'suggest':
          // $this->debug($data[0]);
          return $this->client->Page->SuggestPageShortNames($data[0]);
          break;
      }
    } else {
      return array(
        'result' => FALSE,
        'message' => 'Cannot complete request',
      );
    }
  }
}
