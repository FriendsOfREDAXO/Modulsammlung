<?php

/** @var rex_addon $this */

// Diese Datei wird beim Update eines Addons über den Installer aufgerufen

// Hier können zum Beispiel DB-Tabellen angepasst werden

// $this->getVersion() liefert die noch aktuell installierte Version

if (rex_string::versionCompare($this->getVersion(), '0.1', '<')) {

}

// DB-Anpassungen:
// rex_sql_table::get(rex::getTable('my_table'))
//     ->ensureColumn(new rex_sql_column('new_column', 'varchar(255)'))
//     ->alter()
// ;

// Update kann abgebrochen werden:
// throw new rex_functional_exception('Fehlermeldung');
