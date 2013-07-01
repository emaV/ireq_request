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
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
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
        },
        { "entity_save" : { "data" : [ "node-report" ], "immediate" : 1 } },
        { "workbench_moderation_set_state" : {
            "node" : [ "node-report" ],
            "moderation_state" : "draft",
            "force_transition" : 1
          }
        },
        { "data_set" : {
            "data" : [ "node-report:log" ],
            "value" : "[field-collection-request:field-reporting-type] request by [field-collection-request:field-request-requested-by].\\r\\nWaiting input from [node-report:field-recipient]."
          }
        }
      ]
    }
  }');
  $items['rules_content_published'] = entity_import('rules_config', '{ "rules_content_published" : {
      "LABEL" : "Workflow content type published",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_collection_request_ref" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-collection-request-ref" ],
            "field" : "field_request_requested_by"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-collection-request-ref:field-request-requested-by:mail" ],
            "subject" : "[node:content-type] provided is now published",
            "message" : "Dear [node:field-collection-request-ref:field-request-requested-by:field-first-name] [node:field-collection-request-ref:field-request-requested-by:field-last-name],\\r\\n\\r\\nKindly note that the [node:content-type] for the Information Request has been published.\\r\\n\\r\\n[node:log]\\r\\n\\r\\nThe information can be viewed online: [node:url]\\r\\n\\r\\nNo action is required on your part at this time.\\r\\n\\r\\nKind regards,\\r\\nOCHA",
            "from" : [ "site:mail" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_create_report_from_report_term'] = entity_import('rules_config', '{ "rules_create_report_from_report_term" : {
      "LABEL" : "Create Report from Report term",
      "PLUGIN" : "rule",
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "report_type_term" : { "label" : "Report Type Term", "type" : "taxonomy_term" },
        "field_collection_request" : { "label" : "Field Collection Request", "type" : "field_collection_item" },
        "user_recipient" : { "label" : "Recipient", "type" : "user" },
        "node_report" : { "label" : "Report Node", "type" : "node", "parameter" : false },
        "report_number" : { "label" : "Report Number", "type" : "text" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "report-type-term" ], "field" : "field_content_type" } }
      ],
      "DO" : [
        { "data_convert" : {
            "USING" : { "type" : "token", "value" : [ "report-type-term:field-content-type" ] },
            "PROVIDE" : { "conversion_result" : { "token_node_type" : "Token node type" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : [ "token-node-type" ],
              "param_title" : "[report-type-term:name] [report-number:value]",
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
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "field_collection_request" : { "label" : "Field Collection Request", "type" : "field_collection_item" },
        "user_recipient" : { "label" : "Recipient", "type" : "user" },
        "report_number" : { "label" : "Report Number", "type" : "text" }
      },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "field-collection-request" ],
            "field" : "field_reporting_type"
          }
        }
      ],
      "DO" : [
        { "component_rules_create_report_from_report_term" : {
            "USING" : {
              "report_type_term" : [ "field-collection-request:field-reporting-type" ],
              "field_collection_request" : [ "field_collection_request" ],
              "user_recipient" : [ "user_recipient" ],
              "report_number" : [ "report_number" ]
            },
            "PROVIDE" : { "node_report" : { "node_report" : "Report Node" } }
          }
        }
      ]
    }
  }');
  $items['rules_crf_workflow_simple'] = entity_import('rules_config', '{ "rules_crf_workflow_simple" : {
      "LABEL" : "CRF Workflow simple",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "report" : "report" } } } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_collection_request_ref" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:log" ], "value" : "Automatically published" } },
        { "workbench_moderation_set_state_during_save" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_email_notification_body'] = entity_import('rules_config', '{ "rules_email_notification_body" : {
      "LABEL" : "Email notification body",
      "PLUGIN" : "rule",
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "request_item" : { "label" : "Field Collection Request", "type" : "field_collection_item" },
        "report_url" : { "label" : "Report URL", "type" : "text" },
        "notification_body" : { "label" : "Email Body", "type" : "text", "parameter" : false },
        "request_item_recipient" : { "label" : "Recipient", "type" : "user" }
      },
      "DO" : [
        { "data_set" : {
            "data" : [ "notification-body" ],
            "value" : "Dear [request-item-recipient:field-first-name] [request-item-recipient:field-last-name],\\r\\n\\r\\n[request-item:field-request-requested-by:field-first-name] [request-item:field-request-requested-by:field-last-name] is requesting that you provide [request-item:field-reporting-type:name] information.\\r\\n\\r\\n[request-item:field-append-to-alert-email]\\r\\n\\r\\nKindly provide your information online: [report-url:value]\\r\\n\\r\\nKind regards,\\r\\nOCHA"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "notification_body" ]
    }
  }');
  $items['rules_email_recipients_on_request_submission'] = entity_import('rules_config', '{ "rules_email_recipients_on_request_submission" : {
      "LABEL" : "Email recipients on request submission",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "CRF" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "DO" : []
    }
  }');
  $items['rules_request_submission'] = entity_import('rules_config', '{ "rules_request_submission" : {
      "LABEL" : "Request submission (report creation and notification)",
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
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "1" },
            "PROVIDE" : { "variable_added" : { "report_delta" : "Report delta" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-collection-request" ] },
            "ITEM" : { "request_item" : "Current request item" },
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "request-item:field-request-recipients" ] },
                  "ITEM" : { "request_item_recipient" : "Current request item recipient" },
                  "DO" : [
                    { "variable_add" : {
                        "USING" : { "type" : "text", "value" : "[node:nid]-[report-delta:value]" },
                        "PROVIDE" : { "variable_added" : { "report_number" : "Report Number" } }
                      }
                    },
                    { "component_rules_create_report_from_request_item" : {
                        "field_collection_request" : [ "request-item" ],
                        "user_recipient" : [ "request_item_recipient" ],
                        "report_number" : [ "report_number" ]
                      }
                    },
                    { "component_rules_email_notification_body" : {
                        "USING" : {
                          "request_item" : [ "request-item" ],
                          "report_url" : [ "node:url" ],
                          "request_item_recipient" : [ "request-item-recipient" ]
                        },
                        "PROVIDE" : { "notification_body" : { "notification_body" : "Email Body" } }
                      }
                    },
                    { "mail" : {
                        "to" : "[request-item-recipient:mail]",
                        "subject" : "New [request-item:field-reporting-type] request.",
                        "message" : "Dear [request-item-recipient:field-first-name] [request-item-recipient:field-last-name],\\r\\n\\r\\n[request-item:field-request-requested-by:field-first-name] [request-item:field-request-requested-by:field-last-name] is requesting that you provide [request-item:field-reporting-type:name] information.\\r\\n\\r\\n[request-item:field-append-to-alert-email]\\r\\n\\r\\nKindly provide your information online: [node:url]\\r\\n\\r\\nKind regards,\\r\\nOCHA",
                        "from" : [ "" ],
                        "language" : [ "" ]
                      }
                    },
                    { "data_set" : {
                        "data" : [ "report-delta" ],
                        "value" : { "select" : "report-delta", "num_offset" : { "value" : "1" } }
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
  return $items;
}
