<?php
//owlCarousel_backend
$mediamanager_typ = rex_sql::factory();
$mediamanager_typ->setTable(rex::getTablePrefix().'media_manager_type');
$mediamanager_typ->setValue('name','owlCarousel_backend');
$mediamanager_typ->setValue('description','Zur Darstellung von Bildern im Backend.');

try {
    $mediamanager_typ->insert();
    echo rex_view::success('Der Media Manager "owlCarousel_backend" Typ wurde angelegt. ');
} catch (rex_sql_exception $e) {
    echo rex_view::warning('Der Media Manager "owlCarousel_backend" Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
}

$mediamanager_typ_id = (int) $mediamanager_typ->getLastId();

$mediamanager_typ_effekt = rex_sql::factory();
$mediamanager_typ_effekt->setTable(rex::getTablePrefix().'media_manager_type_effect');
$mediamanager_typ_effekt->setValue('type_id', $mediamanager_typ_id);
$mediamanager_typ_effekt->setValue('priority', 1);
$mediamanager_typ_effekt->setValue('effect', 'resize');
$mediamanager_typ_effekt->setValue('parameters', '{"rex_effect_crop":{"rex_effect_crop_width":"","rex_effect_crop_height":"","rex_effect_crop_offset_width":"","rex_effect_crop_offset_height":"","rex_effect_crop_hpos":"center","rex_effect_crop_vpos":"middle"},"rex_effect_filter_blur":{"rex_effect_filter_blur_repeats":"10","rex_effect_filter_blur_type":"gaussian","rex_effect_filter_blur_smoothit":""},"rex_effect_filter_sharpen":{"rex_effect_filter_sharpen_amount":"80","rex_effect_filter_sharpen_radius":"0.5","rex_effect_filter_sharpen_threshold":"3"},"rex_effect_flip":{"rex_effect_flip_flip":"X"},"rex_effect_header":{"rex_effect_header_download":"open_media","rex_effect_header_cache":"no_cache"},"rex_effect_insert_image":{"rex_effect_insert_image_brandimage":"","rex_effect_insert_image_hpos":"left","rex_effect_insert_image_vpos":"top","rex_effect_insert_image_padding_x":"-10","rex_effect_insert_image_padding_y":"-10"},"rex_effect_mediapath":{"rex_effect_mediapath_mediapath":""},"rex_effect_mirror":{"rex_effect_mirror_height":"","rex_effect_mirror_set_transparent":"colored","rex_effect_mirror_bg_r":"","rex_effect_mirror_bg_g":"","rex_effect_mirror_bg_b":""},"rex_effect_resize":{"rex_effect_resize_width":"250","rex_effect_resize_height":"","rex_effect_resize_style":"maximum","rex_effect_resize_allow_enlarge":"not_enlarge"},"rex_effect_rounded_corners":{"rex_effect_rounded_corners_topleft":"","rex_effect_rounded_corners_topright":"","rex_effect_rounded_corners_bottomleft":"","rex_effect_rounded_corners_bottomright":""},"rex_effect_workspace":{"rex_effect_workspace_width":"","rex_effect_workspace_height":"","rex_effect_workspace_hpos":"left","rex_effect_workspace_vpos":"top","rex_effect_workspace_set_transparent":"colored","rex_effect_workspace_bg_r":"","rex_effect_workspace_bg_g":"","rex_effect_workspace_bg_b":""}}');

try {
    $mediamanager_typ_effekt->insert();
    echo rex_view::success('Der Media Manager Effekt wurde angelegt und kann konfiguriert werden!');
} catch (rex_sql_exception $e) {
    echo rex_view::warning('Der Media Manager Effekt wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
}

//owlCarousel_content
$mediamanager_typ = rex_sql::factory();
$mediamanager_typ->setTable(rex::getTablePrefix().'media_manager_type');
$mediamanager_typ->setValue('name','owlCarousel_content');
$mediamanager_typ->setValue('description','Die normale Größe für die Frontend Ausgabe');

try {
    $mediamanager_typ->insert();
    echo rex_view::success('Der Media Manager "owlCarousel_content" Typ wurde angelegt. ');
} catch (rex_sql_exception $e) {
    echo rex_view::warning('Der Media Manager "owlCarousel_content" Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
}

$mediamanager_typ_id = (int) $mediamanager_typ->getLastId();

$mediamanager_typ_effekt = rex_sql::factory();
$mediamanager_typ_effekt->setTable(rex::getTablePrefix().'media_manager_type_effect');
$mediamanager_typ_effekt->setValue('type_id', $mediamanager_typ_id);
$mediamanager_typ_effekt->setValue('priority', 1);
$mediamanager_typ_effekt->setValue('effect', 'resize');
$mediamanager_typ_effekt->setValue('parameters', '{"rex_effect_crop":{"rex_effect_crop_width":"","rex_effect_crop_height":"","rex_effect_crop_offset_width":"","rex_effect_crop_offset_height":"","rex_effect_crop_hpos":"center","rex_effect_crop_vpos":"middle"},"rex_effect_filter_blur":{"rex_effect_filter_blur_repeats":"10","rex_effect_filter_blur_type":"gaussian","rex_effect_filter_blur_smoothit":""},"rex_effect_filter_sharpen":{"rex_effect_filter_sharpen_amount":"80","rex_effect_filter_sharpen_radius":"0.5","rex_effect_filter_sharpen_threshold":"3"},"rex_effect_flip":{"rex_effect_flip_flip":"X"},"rex_effect_header":{"rex_effect_header_download":"open_media","rex_effect_header_cache":"no_cache"},"rex_effect_insert_image":{"rex_effect_insert_image_brandimage":"","rex_effect_insert_image_hpos":"left","rex_effect_insert_image_vpos":"top","rex_effect_insert_image_padding_x":"-10","rex_effect_insert_image_padding_y":"-10"},"rex_effect_mediapath":{"rex_effect_mediapath_mediapath":""},"rex_effect_mirror":{"rex_effect_mirror_height":"","rex_effect_mirror_set_transparent":"colored","rex_effect_mirror_bg_r":"","rex_effect_mirror_bg_g":"","rex_effect_mirror_bg_b":""},"rex_effect_resize":{"rex_effect_resize_width":"1600","rex_effect_resize_height":"","rex_effect_resize_style":"maximum","rex_effect_resize_allow_enlarge":"not_enlarge"},"rex_effect_rounded_corners":{"rex_effect_rounded_corners_topleft":"","rex_effect_rounded_corners_topright":"","rex_effect_rounded_corners_bottomleft":"","rex_effect_rounded_corners_bottomright":""},"rex_effect_workspace":{"rex_effect_workspace_width":"","rex_effect_workspace_height":"","rex_effect_workspace_hpos":"left","rex_effect_workspace_vpos":"top","rex_effect_workspace_set_transparent":"colored","rex_effect_workspace_bg_r":"","rex_effect_workspace_bg_g":"","rex_effect_workspace_bg_b":""}}');

try {
    $mediamanager_typ_effekt->insert();
    echo rex_view::success('Der Media Manager Effekt wurde angelegt und kann konfiguriert werden!');
} catch (rex_sql_exception $e) {
    echo rex_view::warning('Der Media Manager Effekt wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
}

//owlCarousel_content_retina
$mediamanager_typ = rex_sql::factory();
$mediamanager_typ->setTable(rex::getTablePrefix().'media_manager_type');
$mediamanager_typ->setValue('name','owlCarousel_content_retina');
$mediamanager_typ->setValue('description','Für das data-src-retina und lazyload');

try {
    $mediamanager_typ->insert();
    echo rex_view::success('Der Media Manager "owlCarousel_content_retina" Typ wurde angelegt. ');
} catch (rex_sql_exception $e) {
    echo rex_view::warning('Der Media Manager "owlCarousel_content_retina" Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
}

$mediamanager_typ_id = (int) $mediamanager_typ->getLastId();

$mediamanager_typ_effekt = rex_sql::factory();
$mediamanager_typ_effekt->setTable(rex::getTablePrefix().'media_manager_type_effect');
$mediamanager_typ_effekt->setValue('type_id', $mediamanager_typ_id);
$mediamanager_typ_effekt->setValue('priority', 1);
$mediamanager_typ_effekt->setValue('effect', 'resize');
$mediamanager_typ_effekt->setValue('parameters', '{"rex_effect_crop":{"rex_effect_crop_width":"","rex_effect_crop_height":"","rex_effect_crop_offset_width":"","rex_effect_crop_offset_height":"","rex_effect_crop_hpos":"center","rex_effect_crop_vpos":"middle"},"rex_effect_filter_blur":{"rex_effect_filter_blur_repeats":"10","rex_effect_filter_blur_type":"gaussian","rex_effect_filter_blur_smoothit":""},"rex_effect_filter_sharpen":{"rex_effect_filter_sharpen_amount":"80","rex_effect_filter_sharpen_radius":"0.5","rex_effect_filter_sharpen_threshold":"3"},"rex_effect_flip":{"rex_effect_flip_flip":"X"},"rex_effect_header":{"rex_effect_header_download":"open_media","rex_effect_header_cache":"no_cache"},"rex_effect_insert_image":{"rex_effect_insert_image_brandimage":"","rex_effect_insert_image_hpos":"left","rex_effect_insert_image_vpos":"top","rex_effect_insert_image_padding_x":"-10","rex_effect_insert_image_padding_y":"-10"},"rex_effect_mediapath":{"rex_effect_mediapath_mediapath":""},"rex_effect_mirror":{"rex_effect_mirror_height":"","rex_effect_mirror_set_transparent":"colored","rex_effect_mirror_bg_r":"","rex_effect_mirror_bg_g":"","rex_effect_mirror_bg_b":""},"rex_effect_resize":{"rex_effect_resize_width":"3200","rex_effect_resize_height":"","rex_effect_resize_style":"maximum","rex_effect_resize_allow_enlarge":"not_enlarge"},"rex_effect_rounded_corners":{"rex_effect_rounded_corners_topleft":"","rex_effect_rounded_corners_topright":"","rex_effect_rounded_corners_bottomleft":"","rex_effect_rounded_corners_bottomright":""},"rex_effect_workspace":{"rex_effect_workspace_width":"","rex_effect_workspace_height":"","rex_effect_workspace_hpos":"left","rex_effect_workspace_vpos":"top","rex_effect_workspace_set_transparent":"colored","rex_effect_workspace_bg_r":"","rex_effect_workspace_bg_g":"","rex_effect_workspace_bg_b":""}}');

try {
    $mediamanager_typ_effekt->insert();
    echo rex_view::success('Der Media Manager Effekt wurde angelegt und kann konfiguriert werden!');
} catch (rex_sql_exception $e) {
    echo rex_view::warning('Der Media Manager Effekt wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
}

//redactor 2 owlCarousel Profile
if (rex_addon::get('redactor2')->isAvailable() && !redactor2::profileExists('owlCarousel')) {
    $redactor2_profile = rex_sql::factory();
    $redactor2_profile->setTable(rex::getTablePrefix().'redactor2_profiles');
    $redactor2_profile->setValue('name','owlCarousel');
    $redactor2_profile->setValue('description','Konfiguration für den OwlSlider');
    $redactor2_profile->setValue('urltype','relative');
    $redactor2_profile->setValue('minheight','300');
    $redactor2_profile->setValue('maxheight','800');
    $redactor2_profile->setValue('characterlimit','0');
    $redactor2_profile->setValue('redactor_plugins','alignment,blockquote,italic,bold,underline,deleted,orderedlist,unorderedlist,paragraph,sub,sup,textdirection,fontcolor[Weiss=#ffffff|Schwarz=#000000],fontfamily[Arial|Times],fontsize[12px|15pt|120%],groupheading[1|2|3|4|5|6],grouplink[email|external|internal|media|medialink],redo,undo,cleaner,fullscreen,source');
    $redactor2_profile->setValue('toolbarfixed','0');
    $redactor2_profile->setValue('shortcuts','0');

    try {
        $redactor2_profile->insert();
        echo rex_view::success('Das Redactor Profil "owlCarousel" wurde angelegt. ');
    } catch (rex_sql_exception $e) {
        echo rex_view::warning('Das Redactor Profil "owlCarousel" wurde nicht angelegt.<br/>Wahrscheinlich existiert es schon.');
    }
}