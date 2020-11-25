<?php

/**
 * Permit modules to modify the solr views sort order.
 *
 * @param $orderby
 *   an array field names and sort order, where the field name is the key, and the sort order is the value
 *   e.g. array('fgs_label_s' => 'ASC');
 * @param $context
 *   An array of parameters from islandora_solr_views_query::add_orderby
 *    'table'
 *    'field'
 *    'order'
 *    'alias'
 *    'params'
 */
function hook_islandora_solr_views_sort_alter(&$orderby, $context) {
  if(!empty($context['table']) && $context['table'] == 'rand') {
    if (empty($context['order'])) {
      $context['order'] = 'ASC';
    }
    $orderby['random'] = $context['order'];
  }
}
