// autocomplete stuff
(function($) {

  function checkJGShortName() {
    var $pageShortNameElement = $('#edit-submitted-jg-pagefieldset-jg-shortname');
    var getTemplateContentUrl = "/civicrm/ajax/rest?className=CRM_Justgiving_Page_AJAX&fnName=getPageShortNameSuggestions&json=1'}";
    $.ajax({
      url: getTemplateContentUrl,
      type: "POST",
      data: {pageShortName: $pageShortNameElement.val()},
      async: false,
      datatype: "json",
      success: function (data, status) {
        var pageNames = $.parseJSON(data);
        if (pageNames !== null) {
          $pageShortNameElement.val(pageNames[0]);
        }
      }
    });
  }

  function updateJGShortName() {
    var jgShortName = $('#edit-submitted-jg-pagefieldset-jg-shortname');
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

  function getURLParameter(sParam) {
    var sPageURL = window.location.search.substring(1);
    var sURLVariables = sPageURL.split('&');
    for (var i = 0; i < sURLVariables.length; i++) {
      var sParameterName = sURLVariables[i].split('=');
      if (sParameterName[0] === sParam) {
        return sParameterName[1];
      }
    }
  }

  function selectCharity() {
    var charityId = getURLParameter('charity_id');
    if (charityId) {
      $('#edit-submitted-jg-pagefieldset-jg-charityid option[value="' + charityId + '"]')
        .attr('selected', 'selected');
    }
  }

  // On page load
  $(function() {
    $('#edit-submitted-civicrm-1-contact-1-fieldset-fieldset-civicrm-1-contact-1-contact-first-name').focusout(function() {
      updateJGShortName();
    });
    $('#edit-submitted-civicrm-1-contact-1-fieldset-fieldset-civicrm-1-contact-1-contact-last-name').focusout(function() {
      updateJGShortName();
    });
    $('#edit-submitted-jg-pagefieldset-jg-shortname').focusout(function() {
      updateJGShortName();
    });

    updateJGShortName();
    selectCharity();
  });

})(jQuery);
