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
  $items['rules_check_report_references'] = entity_import('rules_config', '{ "rules_check_report_references" : {
      "LABEL" : "Check Report References",
      "PLUGIN" : "rule",
      "TAGS" : [ "CFR" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "node_report" : { "label" : "Report Node", "type" : "node" },
        "field_collection_request" : { "label" : "Field Collection Request", "type" : "field_collection_item" },
        "user_recipient" : { "label" : "Recipient", "type" : "user" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node-report" ], "field" : "field_collection_request_ref" } },
        { "entity_has_field" : { "entity" : [ "node-report" ], "field" : "field_recipient" } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node-report:field-collection-request-ref" ],
            "value" : [ "field-collection-request" ]
          }
        },
        { "data_set" : { "data" : [ "node-report:author" ], "value" : [ "user-recipient" ] } },
        { "data_set" : {
            "data" : [ "node-report:field-recipient" ],
            "value" : [ "user-recipient" ]
          }
        }
      ]
    }
  }');
  $items['rules_content_published'] = entity_import('rules_config', '{ "rules_content_published" : {
      "LABEL" : "Workflow content type published",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
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
  $items['rules_create_report_from_report_term'] = entity_import('rules_config', '{ "rules_create_report_from_report_term" : {
      "LABEL" : "Create Report from Report term",
      "PLUGIN" : "rule",
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "report_type_term" : { "label" : "Report Type Term", "type" : "taxonomy_term" },
        "field_collection_request" : { "label" : "Field Collection Request", "type" : "field_collection_item" },
        "user_recipient" : { "label" : "Recipient", "type" : "user" },
        "node_report" : { "label" : "Report Node", "type" : "node", "parameter" : false }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "report-type-term" ], "field" : "field_content_type" } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Create Report from Report term:\\u003Cbr\\/\\u003E\\r\\n#[report-type-term:tid]#\\tTerm ID\\tThe unique ID of the taxonomy term.\\r\\n#[report-type-term:field_content_type]#\\tContent type\\tList (text) field.\\r\\n\\r\\n\\u003C?php\\r\\ndpm($report_type_term, \\u0027Create Report from Report term \\u003E $report_type_term\\u0027);\\r\\n?\\u003E" } },
        { "data_convert" : {
            "USING" : { "type" : "token", "value" : [ "report-type-term:field-content-type" ] },
            "PROVIDE" : { "conversion_result" : { "token_node_type" : "Token node type" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : [ "token-node-type" ],
              "param_title" : "[report-type-term:name] [field-collection-request:item-id]-[user-recipient:uid]",
              "param_author" : [ "user-recipient" ]
            },
            "PROVIDE" : { "entity_created" : { "node_report_new" : "Node Report created" } }
          }
        },
        { "data_set" : { "data" : [ "node-report" ], "value" : [ "node-report-new" ] } },
        { "component_rules_check_report_references" : {
            "node_report" : [ "node_report" ],
            "field_collection_request" : [ "field_collection_request" ],
            "user_recipient" : [ "user_recipient" ]
          }
        },
        { "entity_save" : { "data" : [ "node-report" ], "immediate" : 1 } }
      ],
      "PROVIDES VARIABLES" : [ "node_report" ]
    }
  }');
  $items['rules_create_report_from_request_item'] = entity_import('rules_config', '{ "rules_create_report_from_request_item" : {
      "LABEL" : "Create Report from Request item",
      "PLUGIN" : "rule",
      "TAGS" : [ "CFR" ],
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "field_collection_request" : { "label" : "Field Collection Request", "type" : "field_collection_item" },
        "user_recipient" : { "label" : "Recipient", "type" : "user" }
      },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "field-collection-request" ],
            "field" : "field_reporting_type"
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "\\u003C?php\\r\\ndpm($field_collection_request, \\u0027Create Report from Request item \\u003E $field_collection_request\\u0027);\\r\\n?\\u003E" } },
        { "component_rules_create_report_from_report_term" : {
            "USING" : {
              "report_type_term" : [ "field-collection-request:field-reporting-type" ],
              "field_collection_request" : [ "field_collection_request" ],
              "user_recipient" : [ "user_recipient" ]
            },
            "PROVIDE" : { "node_report" : { "node_report" : "Report Node" } }
          }
        },
        { "drupal_message" : { "message" : "\\u003C?php\\r\\ndpm($node_report, \\u0022Create Report from Request item \\u003E node_report\\u0022);\\r\\ndpm($field_collection_request, \\u0022Create Report from Request item \\u003E field_collection_request\\u0022);\\r\\n?\\u003E\\r\\n\\r\\n" } },
        { "drupal_message" : { "message" : "Done:\\r\\n\\u003C?php\\r\\ndpm($node_report, \\u0027done: $node_report\\u0027);\\r\\n\\/\\/dpm($node_report_final, \\u0027done: $node_report_final\\u0027);\\r\\n?\\u003E" } }
      ]
    }
  }');
  $items['rules_email_recipients_on_request_submission'] = entity_import('rules_config', '{ "rules_email_recipients_on_request_submission" : {
      "LABEL" : "Email recipients on request submission",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "CRF" ],
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
              { "LOOP" : {
                  "USING" : { "list" : [ "request-item:field-request-recipients" ] },
                  "ITEM" : { "request_item_recipient" : "Current request item recipient" },
                  "DO" : [
                    { "component_rules_create_report_from_request_item" : {
                        "field_collection_request" : [ "request-item" ],
                        "user_recipient" : [ "request_item_recipient" ]
                      }
                    },
                    { "mail" : {
                        "to" : "[request-item-recipient:mail]",
                        "subject" : "New [request-item:field-reporting-type] request.",
                        "message" : "Dear [request-item-recipient:field-first-name] [request-item-recipient:field-last-name],\\r\\n\\r\\n[request-item:field-request-requested-by:field-first-name] [request-item:field-request-requested-by:field-last-name] is requesting that you provide [request-item:field-reporting-type:name] information.\\r\\n\\r\\n[request-item:field-append-to-alert-email]\\r\\n\\r\\nKindly provide your information online: [node:url]\\r\\n\\r\\nKind regards,\\r\\nOCHA",
                        "from" : [ "" ],
                        "language" : [ "" ]
                      }
                    }
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
      "ACTIVE" : false,
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
