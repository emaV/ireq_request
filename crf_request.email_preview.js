(function ($) {

  Drupal.behaviors.previewRequestEmail = {
    attach: function(context, settings) {
      $('table#report-request-preview tr.mail-preview').hide();
      $('table#report-request-preview span.link-preview:not(.request-preview-processed)')
        .addClass('request-preview-processed')
        .click( function() {
          $(this).closest('tr').next('tr').toggle();
        });
    }
  }
})(jQuery);
