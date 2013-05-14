<?php
/**
 * @file
 * crf_request.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crf_request_default_rules_configuration() {
  $items = array();
  $items['rules_content_published'] = entity_import('rules_config', '{ "rules_content_published" : {
      "LABEL" : "Workflow content type published",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-request" ],
            "field" : "field_request_recipients"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-request:field-request-recipients:0:mail" ],
            "subject" : "[node:content-type] provided for [node:field-request:title] is now published",
            "message" : "Dear [node:field-request:field-request-recipients:0:field-first-name] [node:field-request:field-request-recipients:0:field-last-name],\\r\\n\\r\\nKindly note that the [node:content-type] for the Information Request [node:field-request:title] has been published.\\r\\n\\r\\n[node:log]\\r\\n\\r\\nThe information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "site:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  $items['rules_email_recipients_on_request_submission'] = entity_import('rules_config', '{ "rules_email_recipients_on_request_submission" : {
      "LABEL" : "Email recipients on request submission",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "request" : "request" } } } },
        { "entity_has_field" : {
            "entity" : [ "node:field-collection-request:0" ],
            "field" : "field_request_recipients"
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-collection-request" ] },
            "ITEM" : { "request_item" : "Current request item" },
            "DO" : [
              { "drupal_message" : { "message" : "Reporting types: [request-item:field-reporting-type]\\r\\nAppend to Information Request email: [request-item:field-append-to-alert-email]" } },
              { "LOOP" : {
                  "USING" : { "list" : [ "request-item:field-request-recipients" ] },
                  "ITEM" : { "request_item_recipient" : "Current request item recipient" },
                  "DO" : [
                    { "drupal_message" : { "message" : "Mail: [request-item-recipient:mail]\\r\\nName: [request-item-recipient:name]" } }
                  ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_workflow_content_type_submitted_to_ocha'] = entity_import('rules_config', '{ "rules_workflow_content_type_submitted_to_ocha" : {
      "LABEL" : "Workflow content type submitted to OCHA",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules", "workbench_access" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "submitted_to_ocha" } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "assessments_batch" : "assessments_batch",
                "contacts_upload" : "contacts_upload",
                "indicator_data_batch" : "indicator_data_batch",
                "sectoral_analysis" : "sectoral_analysis",
                "hr_sitrep" : "hr_sitrep"
              }
            }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_request" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-request" ],
            "field" : "field_request_requested_by"
          }
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "user",
              "id" : [ "node:field-request:field-request-requested-by:0:uid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "ocha_user" : "OCHA user" } }
          }
        },
        { "data_set" : { "data" : [ "node:author" ], "value" : [ "ocha-user" ] } },
        { "workbench_access_assign_access_section" : { "node" : [ "node" ], "access_section" : "1" } },
        { "mail" : {
            "to" : [ "node:field-request:field-request-requested-by:0:mail" ],
            "subject" : "[node:content-type] provided by [site:current-user:field-first-name] [site:current-user:field-last-name] for [node:field-request:title]",
            "message" : "Dear [node:field-request:field-request-requested-by:0:field-first-name] [node:field-request:field-request-requested-by:0:field-last-name],\\r\\n\\r\\nKindly note that [site:current-user:field-first-name] [site:current-user:field-last-name] has uploaded a [node:content-type] for the Information Request [node:field-request:title] to the CRF website.\\r\\n\\r\\n[node:log]\\r\\n\\r\\nThe data can be reviewed at: [node:url]\\r\\n\\r\\nAt this point, we encourage you review the submission. If changes are required, you can make the necessary edits and send the information back to [site:current-user:field-first-name] [site:current-user:field-last-name] by selecting \\u0022Request Review\\u0022. If the information is complete, you can finish the process by selecting \\u0022Finalise\\u0022.\\r\\n\\r\\nKind regards.",
            "from" : [ "site:current-user:mail" ],
            "language" : [ "" ]
          }
        },
        { "redirect" : { "url" : "\\u003Cfront\\u003E" } }
      ]
    }
  }');
  return $items;
}
