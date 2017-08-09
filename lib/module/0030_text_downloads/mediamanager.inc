<?php
  $mediamanager_typ = rex_sql::factory();
  $mediamanager_typ->setTable('rex_media_manager_type');
        $mediamanager_typ->setValue('name','download');
        $mediamanager_typ->setValue('description','Zum Download von Dateien.');

        try {
          $mediamanager_typ->insert();
          echo rex_view::success('Der Media Manager "download" Typ wurde angelegt. ');
        } catch (rex_sql_exception $e) {
              echo rex_view::warning('Der Media Manager "download" Typ wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
        }

        $mediamanager_typ_id = (int) $mediamanager_typ->getLastId();

        $mediamanager_typ_effekt = rex_sql::factory();
        $mediamanager_typ_effekt->setTable('rex_media_manager_type_effect');
        $mediamanager_typ_effekt->setValue('type_id', $mediamanager_typ_id);
        $mediamanager_typ_effekt->setValue('priority', 1);
        $mediamanager_typ_effekt->setValue('effect', 'header');
        $mediamanager_typ_effekt->setValue('parameters', '{"rex_effect_header":{"rex_effect_header_download":"download","rex_effect_header_cache":"no_cache"}}');
        try {
          $mediamanager_typ_effekt->insert();
          echo rex_view::success('Der Media Manager Effekt wurde angelegt und kann konfiguriert werden!');
        } catch (rex_sql_exception $e) {
              echo rex_view::warning('Der Media Manager Effekt wurde nicht angelegt.<br/>Wahrscheinlich existiert er schon.');
        }
