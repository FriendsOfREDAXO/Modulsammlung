<?php

/** @var rex_addon $this */

// Diese Datei ist keine Pflichtdatei mehr.

// SQL-Anweisungen können auch weiterhin über die uninstall.sql ausgeführt werden.

// Mit einer rex_functional_exception kann die Deistallation mit einer Fehlermeldung abgebrochen werden.
$somethingIsWrong = false;
if ($somethingIsWrong) {
    throw new rex_functional_exception('Something is wrong');
}

// Alternativ kann ähnlich wie in R4 mit den Properties "install" und "installmsg" die Deinstallation als nicht erfolgreich markiert werden.
// Im Gegensatz zu R4 muss für eine erfolgreiche Deinstallation keine Property mehr gesetzt werden.
if ($somethingIsWrong) {
    $this->setProperty('installmsg', 'Something is wrong');
    $this->setProperty('install', true);
}
