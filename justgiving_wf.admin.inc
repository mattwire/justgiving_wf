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
  // Quick fix for live site which uses registration_form type for most webforms.
  $nodes = array_merge($nodes, node_load_multiple(array() , array('type' => 'registration_form')));
  $forms = array('' => 'None');
  if($nodes && !empty($nodes)){
    foreach ($nodes as $node) {
      $forms[$node->nid] = $node->title;
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
          'sandbox' => t('Sandbox'),
          'live' => t('Live'),
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
    );
  return system_settings_form($form);
}
