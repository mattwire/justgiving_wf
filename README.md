# justgiving_wf
This allows a webform to interact with the justgiving API.

## Required

  * uk.co.mjwconsult.justgiving CiviCRM extension enabled and configured.
  * Symlink to sites/all/libraries/justgiving from uk.co.mjwconsult.justgiving/src/JustgivingPHP

## Setup

1. Configure under Drupal Configuration->Web Services->JustGiving
1. Specify the following fields in the webform (for the justgiving account):
    * ['civicrm_1_contact_1_fieldset_fieldset']['jg_createaccount'] (checkbox, optional)
    * ['civicrm_1_contact_1_fieldset_fieldset']['civicrm_1_contact_1_email_email'] (textfield, required)
    * ['civicrm_1_contact_1_fieldset_fieldset']['jg_password'] (textfield/password, required)
    * ['civicrm_1_contact_1_fieldset_fieldset']['civicrm_1_contact_1_contact_prefix_id'] (select, optional)
    * ['civicrm_1_contact_1_fieldset_fieldset']['civicrm_1_contact_1_contact_first_name'] (textfield, required)
    * ['civicrm_1_contact_1_fieldset_fieldset']['civicrm_1_contact_1_contact_last_name'] (textfield, required)
    * ['civicrm_1_contact_1_fieldset_fieldset']['civicrm_1_contact_1_address_street_address'] (textfield, required)
    * ['civicrm_1_contact_1_fieldset_fieldset']['civicrm_1_contact_1_address_city'] (textfield, required)
    * ['civicrm_1_contact_1_fieldset_fieldset']['civicrm_1_contact_1_address_postal_code'] (textfield, required)
1. Specify the following in the webform (for the justgiving page):
    * 'jg_charityid' (int, required, hidden?)
    * 'jg_eventid' (int, required, hidden?)
    * 'jg_shortname' (textfield, required)
    * 'jg_pagetitle' (textfield, required)
    * 'jg_pagestory' (textarea, optional)
    * 'jg_targetamount' (int, optional)

## Credits
Drupal module based on (https://www.drupal.org/sandbox/KrisPomphrey/2202035)