<?php
/////////////////
// Fusion Apply
/////////////////

function nova_bs_fusion_apply_group_nova_bs_skins_info() {
  $groups = array();
  $groups['region_specific'] = array(
    'title' => t('Region specific'),
    'description' => t('Skins dependent on content'),
    'weight' => 20,
  );

  return $groups;
}

function nova_bs_fusion_apply_skin_nova_bs_skins_info() {
  $skins = array();

  $skins['site_title'] = array(
    'title' => t('Site title'),
    'type' => 'checkboxes',
    'description' => t('Apply to the site-title blocks'),
    'group' => 'region_specific',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => array(
      'nova-site-title' => array(
        'title' => 'Is a site title',
        'class' => array('fa-site-title'),
      ),
    ),
  );

  $skins['span_columns'] = array(
    'title' => t('Span columns'),
    'description' => t("Set the width of this block, measured in columns (units of a 5-column grid). The width will not be applied if its wider than container width."),
    'type' => 'select',
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => _nova_bs_skins_span_columns(),
  );

  $skins['apply_omega'] = array(
    'title' => t('Apply omega when container width is equal to or less than'),
    'description' => t("…units of a 5-column grid."),
    'type' => 'select',
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => _nova_bs_skins_apply_omega(),
  );

  /* Cycle through breakpoints to generate a prefence for each breakpoint. */
  foreach (array_slice(_nova_bs_columns(),1,count(_nova_bs_columns()) - 1) as $i) {
    $skins["span_columns_bp_{$i}"] = array(
      'title' => t("When the window is exactly {$i} columns wide, span columns"),
      'description' => t("Set the width of this block, applied only when window fits {$i} columns."),
      'type' => 'select',
      'group' => 'layout',
      'theme hooks' => array('block'),
      'default status' => TRUE,
      'options' => _nova_bs_skins_span_columns_bp($i),
    );
  }

  return $skins;
}

/**
 * Generates fusion_apply options based on grid parameters.
 * @return array
 */
function _nova_bs_skins_span_columns() {
  $options = array();

  /* Cycle through all integers starting with 1 and ending with largest breakpoint. */
  for ($col = 1; $col <= end(_nova_bs_columns()); $col++) {
    $plural = ($col == 1) ? '' : 's';

    /* Add a span value */
    $options["fa-span-{$col}"] = array(
      'title' => "$col unit{$plural}",
      'class' => "fa-span-{$col}"
    );

    /* Add a span value with omega */
    if ($col != end(_nova_bs_columns())) {
      $options["fa-span-{$col}-omega"] = array(
        'title' => "$col unit{$plural}, omega",
        'class' => "fa-span-{$col}-omega"
      );
    }
  }

  return $options;
}
function _nova_bs_skins_apply_omega() {
  $options = array();

  /* Cycle through breakpoints starting with the second one. */
  foreach (array_slice(_nova_bs_columns(),1,count(_nova_bs_columns()) - 1) as $bp) {
    $plural = ($bp == 1) ? '' : 's';

    /* Add omega */
    $options["fa-apply-omega-bp-{$bp}"] = array(
    'title' => "$bp unit{$plural}",
    'class' => "fa-apply-omega-bp-{$bp}"
    );
  }

  return $options;
}
function _nova_bs_skins_span_columns_bp($width) {
  $options = array();

  /* Cycle through all integers starting with 1 and ending with largest breakpoint. */
  for ($col = 1; $col <= end(_nova_bs_columns()); $col++) {
    $plural = ($col == 1) ? '' : 's';

    /* Add a span value */
    if ($col <= $width) {
      $options["fa-bp-{$width}-span-{$col}"] = array(
        'title' => "$col unit{$plural}",
        'class' => "fa-bp-{$width}-span-{$col}"
      );
    }

    /* Add a span value with omega */
    if ($col < $width) {
      $options["fa-bp-{$width}-span-{$col}-omega"] = array(
        'title' => "$col unit{$plural}, omega",
        'class' => "fa-bp-{$width}-span-{$col}-omega"
      );
    }
  }

  return $options;
}
function _nova_bs_columns() {
  return explode(" ", theme_get_setting('columns_list'));
}