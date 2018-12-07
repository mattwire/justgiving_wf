<?php

class justgiving_wf_data {

  /**
   * The map of Justgiving charity_id => CiviCRM "participant" Group
   *
   * @var array $groupMap
   */
  public static $groupMap = [
    11119 => 134, // Age Scotland
    2327 => 136, // Alzheimer Scotland
    185854 => 160, // Army Cadet Force
    182003 => 159,  // Brain Tumour Charity
    2448850 => 155, // Craigies Education and Environment Project SCIO
    11349 => 140, // CHAS
    2367 => 142, // Children 1st
    183178 => 145, // Crossreach
    320 => 137, // Cystic Fibrosis Trust
    168132 => 146, // Edinburgh Children’s Hospital Charity
    //    185854 => 112, // Kirkliston Scouts
    2116 => 147, // Macmillan Cancer Support
    11233 => 139, // Parkinson's UK in Scotland
    183007 => 158, // ProjectScotland
    2451957 => 141, // QCCC
    182055 => 144, // St Andrew's Hospice
    190325 => 143, // St Columba's Hospice
    246611 => 148, // Strathcarron Hospice
    //   185854 => 107, // The Rotary Club of South Queensferry
    186311 => 138, // The Yard
    //    185854 => 120, // Tom Thumb Nursery
    167956 => 156, // VOCAL
  ];

  /**
   * @var int default CiviCRM group ID if not matched in $groupMap
   */
  public static $defaultGroup = 146;

  public static $fieldMap = [
    'jg_createaccount' => 'civicrm_1_contact_1_fieldset_fieldset:jg_createaccount:1',
    'jg_createpage' => 'civicrm_1_contact_1_fieldset_fieldset:jg_createpage:1',
    'jg_email' => 'civicrm_1_contact_1_fieldset_fieldset:civicrm_1_contact_1_email_email',
    'jg_password' => 'civicrm_1_contact_1_fieldset_fieldset:jg_password',
    'jg_prefix' => 'civicrm_1_contact_1_fieldset_fieldset:my_name:civicrm_1_contact_1_contact_prefix_id',
    'jg_firstname' => 'civicrm_1_contact_1_fieldset_fieldset:my_name:civicrm_1_contact_1_contact_first_name',
    'jg_lastname' => 'civicrm_1_contact_1_fieldset_fieldset:my_name:civicrm_1_contact_1_contact_last_name',
    'jg_address1' => 'civicrm_1_contact_1_fieldset_fieldset:civicrm_1_contact_1_address_street_address',
    'jg_city' => 'civicrm_1_contact_1_fieldset_fieldset:civicrm_1_contact_1_address_city',
    'jg_postcode' => 'civicrm_1_contact_1_fieldset_fieldset:civicrm_1_contact_1_address_postal_code',
    'jg_charityid' => 'jg_pagefieldset:jg_charityid',
    'jg_eventid' => 'jg_pagefieldset:jg_eventid',
    'jg_shortname' => 'jg_pagefieldset:jg_shortname',
    'jg_pagetitle' => 'jg_pagefieldset:jg_pagetitle',
  ];

  public static function setField(&$submitted, $name, $value) {
    switch ($name) {
      case 'jg_createaccount':
        $submitted['civicrm_1_contact_1_fieldset_fieldset']['jg_createaccount'][1] = $value;
        break;
    }

  }
}
