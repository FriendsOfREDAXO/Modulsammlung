<?php

if (rex::getUser()->isAdmin()) {

    $content = '';
    $searchtext = 'modul:grundinstalltion_ohne_aenderungen';

    $gm = rex_sql::factory();
    $gm->debugsql = 1;
    $gm->setQuery('select * from rex_module where output LIKE "%' . $searchtext . '%"');

    $module_id = 0;
    $module_name = '';
    foreach ($gm->getArray() as $module) {
        $module_id = $module['id'];
        $module_name = $module['name'];
    }

    $grid_modul_builder_module_name = '0010 - Responsive Content';

    if (rex_request('install',"integer") == 1) {

        $input = rex_file::get(rex_path::addon('grid_modul_builder','module/module_input.inc'));
        $output = rex_file::get(rex_path::addon('grid_modul_builder','module/module_output.inc'));

        $mi = rex_sql::factory();
        $mi->debugsql = 1;
        $mi->setTable('rex_module');
        $mi->setValue('input', $input);
        $mi->setValue('output', $output);

        if ($module_id == rex_request('module_id','integer',-1)) {
            $mi->setWhere('id="' . $module_id . '"');
            $mi->update();
            echo rex_view::success('Das Modul "' . $module_name . '" wurde aktualisiert');

        } else {
            $mi->setValue('name', $grid_modul_builder_module_name);
            $mi->insert();
            $module_id = (int) $mi->getLastId();
            $module_name = $grid_modul_builder_module_name;
            echo rex_view::success('Das Modul "' . $grid_modul_builder_module_name . '" wurde angelegt. ');
        }
    }

    $content .= '<p>'.$this->i18n('install_modul_description').'<br /><br />';

    if ($module_id > 0) {
        $content .= '<p><a class="btn btn-primary" href="index.php?page=grid_modul_builder/install&amp;install=1&amp;module_id=' . $module_id . '" class="rex-button">' . $this->i18n('grid_modul_builder_install_update_modul', htmlspecialchars($module_name)) . '</a></p>';

    }else {
        $content .= '<p><a class="btn btn-primary" href="index.php?page=grid_modul_builder/install&amp;install=1" class="rex-button">' . $this->i18n('grid_modul_builder_install_modul', $grid_modul_builder_module_name) . '</a></p>';

    }
    $content .= '</p>';

    $fragment = new rex_fragment();
    $fragment->setVar('class', 'info');
    $fragment->setVar('title', $this->i18n('install_modul'), false);
    $fragment->setVar('body', $content , false);
    echo $fragment->parse('core/page/section.php');

}


