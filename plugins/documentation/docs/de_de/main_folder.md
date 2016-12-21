# Ordner-Struktur

Struktur:

    assets
        documentation.css
        documentation.js
    docs
        de_de
            main_intro.md
            main_navi.md
            ...
        en_gb
    lang
        de_de.lang
        en_gb.lang
    pages
        index.php

    boot.php
    package.yml
    README.md

> **Hinweis:**<br>Die für die Dokumentation wichtigen bzw. anzupassenden Verzeichnisse und Dateien sind `hervorgehoben`.

Verzeichnis / Datei|Beschreibung
------ | ------
**assets**|Verzeichnis für die Addon-Ressourcen
-&nbsp;documentation.css|CSS für die Dokumentation im REDAXO-Backend
-&nbsp;documentation.js|JavaScript für die Dokumentation im REDAXO-Backend
**docs**|Verzeichnis für die Dokumentationen in verschiedenen Sprachen, die Namen der Unterordner müssen den REDAXO-Backendsprachen entsprechen (z.B. de_de, en_gb)
`de_de`|Verzeichnis Dokumentation in deutsch, hier liegen alle Markdown-Dateien und Bilder der Dokumentation
-&nbsp;`main_intro.md`|Einstiegsseite der Dokumentation, diese Datei wird beim ersten Aufruf der Dokumentation im Backend angezeigt (default, kann in der package.yml angepasst werden)
-&nbsp;`main_navi.md`|Navigation der Dokumentation (default, kann in der package.yml angepasst werden)
**en_gb**|Verzeichnis Dokumentation in englisch
**lang**|Verzeichnis Sprachdateien des Addons
-&nbsp;de_de.lang|Addon-Texte in deutsch
-&nbsp;en_gb.lang|Addon-Texte in englisch
**pages**|Verzeichnis Seiten des Addons
-&nbsp;index.php|Hier spielt die Musik, parsen der Markdown-Dateien, anpassen für das REDAXO-Backend und Ausgabe
boot.php|Laden der Addon-Ressourcen
`package.yml`|Addon-Konfiguration, hier können auch die Default-Dateinamen angepasst werden
`README.md`|Readme-Datei die auf Github und im REDAXO-Backend (Addon-Hilfe) angezeigt wird

> **Hinweis:**<br>Alle Dateien der Dokumentation liegen in _einem_ Verzeichnis z.B. `/docs/de_de/`. Bei der Namensvergabe für die Dateien empfiehlt es sich die zusammengehörigen Dateien zu gruppieren z.B. `main_*.md` ... `howto_*.md`.

---

&raquo; Weiter zur **[Plugin-Integration](howto_copy.md)**
