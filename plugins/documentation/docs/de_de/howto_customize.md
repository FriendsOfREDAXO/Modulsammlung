# Anpassungen

- [Anpassen der `package.yml`](#package)
- [Anpassen der `README.md`](#readme)
- [Dokumentation](#dokumentation)

<a name="package"></a>
## Anpassen der `package.yml`

Beispiel:

    package: dummy/documentation
    version: '1.0.0'
    author: 'Friends Of REDAXO'
    supportpage: github.com/FriendsOfREDAXO/dummy_documentation

    documentationlang: 'de_de'
    defaultnavi: 'main_navi.md'
    defaultintro: 'main_intro.md'

    page:
        title: 'translate:documentation_menu_entry'
        icon: rex-icon fa-book
        perm: admin[]

> **Hinweis:**<br>Die `package.yml` sollte komplett an dein Addon und deine Dokumentation angepasst sein.<br>Wichtig ist es den Eintrag **package** anzupassen da sonst die Installation nicht funktioniert.

Eintrag|Beschreibung
------ | ------
package|`dummy/documentation` muss angepasst werden in `DeinAddonName/documentation` da sonst die Installation des Plugins in der Addon-Verwaltung nicht funktioniert.
version|Versionsnummer deiner Dokumentation
author|Angaben über den Autor
supportpage|Supportpage für dein Addon
documentationlang|Sprache der Dokumentation _(optional)_<br>Standardmässig wird die bei dem Benutzer eingestellte Backendsprache verwendet. Wenn es die Dokumentation aber nur in einer Sprache gibt dann sollte hier die Sprache angegeben werden.
defaultnavi|Default-Dateiname für die Navigation<br>Default ist `main_navi.md` wenn nichts angegeben wird
defaultintro|Default-Dateiname für die Einstiegsseite<br>Default ist `main_intro.md` wenn nichts angegeben wird
title|Dieser Text wird im Reiter deiner Addon-Navigation angezeigt

---

<a name="readme"></a>
## Anpassen der `README.md`

> **Hinweis:**<br>Die `README.md` wird auf Github und in der Addon-Verwaltung bei Klick auf das Fragezeichen angezeigt.

Beispiel:

    # Plugin "Dokumentation-Dummy" für REDAXO5-AddOns

    Das Plugin `dummy_documentation` dient als Basis für eine Hilfe/Dokumentation für REDAXO5-AddOns bei denen eine einfache README nicht ausreicht.
    Für weitere Informationen zu diesem Plugin siehe [docs/de_de/main_navi.md](docs/de_de/main_navi.md)

    ---

    Inhaltsverzeichnis: [docs/de_de/main_navi.md](docs/de_de/main_navi.md)

    Vorlage zur Formatierung: [docs/de_de/_vorlage.md](docs/de_de/_vorlage.md)

---

<a name="dokumentation"></a>
## Dokumentation

Jetzt geht es ans eingemachte. Im Verzeichnis `docs\de_de` kann diese bestehende Dokumentation vom Plugin `documentation` als Basis verwendet und entsprechend angepasst werden.

Weitere nützliche Informationen findest Du evtl. noch unter [Hilfe / FAQ](help_where.md) oder in der [Markdown-Vorlage](_vorlage.md).

Viel Spass !!

> **Hinweis:**<br>Alle Dateien der Dokumentation liegen in _einem_ Verzeichnis z.B. `/docs/de_de/`. Bei der Namensvergabe für die Dateien empfiehlt es sich die zusammengehörigen Dateien zu gruppieren z.B. `main_*.md` ... `howto_*.md`.

---

&raquo; Weiter zu **[Hilfe / FAQ](help_where.md)**