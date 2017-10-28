// autocomplete stuff
(function($) {

  function checkJGShortName() {
    var $pageShortNameElement = $('#edit-submitted-jg-shortname');
    var getTemplateContentUrl = "/civicrm/ajax/rest?className=CRM_Justgiving_Page_AJAX&fnName=getPageShortNameSuggestions&json=1'}";
    $.ajax({
      url: getTemplateContentUrl,
      type: "POST",
      data: {pageShortName: $pageShortNameElement.val()},
      async: false,
      datatype: "json",
      success: function (data, status) {
        var pageNames = $.parseJSON(data);
        if (pageNames !== NULL) {
          $pageShortNameElement.val(pageNames[0]);
        }
      }
    });
  }

  function updateJGShortName() {
    var jgShortName = $('#edit-submitted-jg-shortname');
    var jgFirstName = $('#edit-submitted-civicrm-1-contact-1-fieldset-fieldset-civicrm-1-contact-1-contact-first-name');
    var jgLastName = $('#edit-submitted-civicrm-1-contact-1-fieldset-fieldset-civicrm-1-contact-1-contact-last-name');
    var webformSubmit = $('.webform-submit');
    // Check elements are defined
    if (!jgShortName.length) {
      return
    }

    webformSubmit.attr('disabled', true);
    var submitText = webformSubmit.text();
    webformSubmit.html('Wait...');

    // Check elements are defined
    if (jgFirstName.length && jgLastName.length) {
      if (!jgShortName.val().length && jgFirstName.val().length && jgLastName.val().length) {
        var shortName = jgFirstName.val() + jgLastName.val();
        jgShortName.val(shortName);
      }
    }
    checkJGShortName();
    webformSubmit.html(submitText);
    webformSubmit.attr('disabled', false);
  }

  // On page load
  $(function() {
    updateJGShortName();

    $('#edit-submitted-civicrm-1-contact-1-fieldset-fieldset-civicrm-1-contact-1-contact-first-name').focusout(function() {
      updateJGShortName();
    });
    $('#edit-submitted-civicrm-1-contact-1-fieldset-fieldset-civicrm-1-contact-1-contact-last-name').focusout(function() {
      updateJGShortName();
    });
    $('#edit-submitted-jg-shortname').focusout(function() {
      updateJGShortName();
    });
  });

})(jQuery);
