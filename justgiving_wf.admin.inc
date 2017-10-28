<?php
/**
 * @file
 * Admin page for JustGiving integration
 */

/**
 * Just Giving integration administration settings.
 *
 * Forms for administrator to set configuration options.
 *
 * @return form
 */
function justgiving_wf_admin() {
  $nodes = node_load_multiple(array(), array('type' => 'webform'));
  $forms = array('' => 'None');
  if($nodes && !empty($nodes)){
    foreach ($nodes as $node) {
      $forms[$node->nid] = $node->title;
      if($node->webform['components'] && !empty($node->webform['components'])){
        foreach($node->webform['components'] as $component){
          $fields[$node->nid][$component['form_key']] = $component['name'];
        }
      }
    }
  }
  $form = array(
    'justgiving_general_fieldset' => array(
      '#type' => 'fieldset',
      '#title' => 'General Settings',
      '#collapsible' => TRUE,
      'justgiving_api_key' => array(
        '#type' => 'textfield',
        '#title' => t('API Key'),
        '#default_value' => variable_get('justgiving_api_key'),
        '#size' => 50,
        '#maxlength' => 100,
        '#description' => t('This is the key generated in the Just Giving API Dashboard'),
        '#required' => TRUE,
        ),
      'justgiving_environment' => array(
        '#type' => 'select',
        '#title' => 'Environment',
        '#default_value' => variable_get('justgiving_environment'),
        '#options' => array(
          'https://api.sandbox.justgiving.com/' => t('Sandbox'),
          'https://api.staging.justgiving.com/' => t('Staging'),
          'https://api.justgiving.com/' => t('Live'),
          ),
        '#description' => t('The environment used for Just Giving integration'),
      ),
    ),
    'justgiving_forms_fieldset' => array(
      '#type' => 'fieldset',
      '#title' => 'Forms',
      '#collapsible' => TRUE,
      '#collapsed'  => TRUE,
      'justgiving_node_page_form' => array(
        '#type' => 'select',
        '#title' => 'Page Creation Form',
        '#default_value' => variable_get('justgiving_node_page_form'),
        '#options' => $forms,
        ),
      ),
      'justgiving_suggestions_fieldset' => array(
        '#type' => 'fieldset',
        '#title' => 'URL Suggestions',
        '#collapsible' => TRUE,
        '#collapsed'  => TRUE,
        'justgiving_suggestions_choice' => array(
          '#type' => 'radios',
          '#title' => '',
          '#default_value' => variable_get('justgiving_suggestions_choice'),
          '#options' => array(
              'default' => 'JustGiving Default Suggestions',
              'custom' => 'Custom Suggestion',
            ),
          ),
        'justgiving_suggestions_choice_custom' => array(
          '#type' => 'textfield',
          '#title' => '',
          '#default_value' => variable_get('justgiving_suggestions_choice_custom'),
          '#description' => 'Pattern will be FIRST_NAME-YOUR_CUSTOM_SUGGESTION',
        ),
      ),
    );
  return system_settings_form($form);
}
