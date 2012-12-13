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
  foreach (array_slice(_nova_bs_columns(),0,count(_nova_bs_columns()) - 1) as $i) {
    $plural = ($i == 1) ? '' : 's';
    $options["fa-span-{$i}"] = array(
      'title' => "$i unit{$plural}",
      'class' => "fa-span-{$i}"
    );
  }
  foreach (array_slice(_nova_bs_columns(),0,count(_nova_bs_columns()) - 1) as $i) {
    $plural = ($i == 1) ? '' : 's';
    $options["fa-span-{$i}-omega"] = array(
      'title' => "$i unit{$plural}, omega",
      'class' => "fa-span-{$i}-omega"
    );
  }

  return $options;
}
function _nova_bs_skins_apply_omega() {
  $options = array();
  foreach (array_slice(_nova_bs_columns(),1,count(_nova_bs_columns()) - 1) as $i) {
    $plural = ($i == 1) ? '' : 's';
    $options["fa-apply-omega-{$i}"] = array(
      'title' => "$i columns{$plural}",
      'class' => "fa-apply-omega-{$i}"
    );
  }
  return $options;
}
function _nova_bs_skins_span_columns_bp($width) {
  $options = array();
  foreach (array_slice(_nova_bs_columns(),0,count(_nova_bs_columns()) - 1) as $i) {
    if ($i <= $width) {
      $plural = ($i == 1) ? '' : 's';
      $options["fa-span-{$i}"] = array(
        'title' => "$i unit{$plural}",
        'class' => "fa-bp-{$width}-span-{$i}"
      );
    }
  }
  foreach (array_slice(_nova_bs_columns(),0,count(_nova_bs_columns()) - 1) as $i) {
    if ($i <= $width) {
      $plural = ($i == 1) ? '' : 's';
      $options["fa-span-{$i}-omega"] = array(
        'title' => "$i unit{$plural}, omega",
        'class' => "fa-bp-{$width}-span-{$i}-omega"
      );
    }
  }

  return $options;
}
function _nova_bs_columns() {
  return explode(" ", theme_get_setting('columns_list'));
}