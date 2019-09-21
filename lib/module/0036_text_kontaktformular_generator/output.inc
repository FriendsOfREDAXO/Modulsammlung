  <?php 
/**==================================================
 * REDAXO-Modul: Formulargenerator do form!
 * Bereich: Ausgabe
 * Version: 6.2.1
 *==================================================*/
//   SETTINGS
$form_tag_class 	     = 'doform doajax'; // CSS Klasse des FORM-Tags
$form_field_wrp		     = 'formblock'; // Wrapper-Class für die Formularfelder
$form_warn_css               = 'class="formerror"'; // Label-Stildefinition für Fehler
$form_warnblock_css          = 'formerror'; // Wrapper-Fehler-Klasse
$form_subject = $subject     = 'REX_VALUE[4]'; // Überschrift / Betreff der E-Mail
$form_ID                     = "doform" . "REX_SLICE_ID"; // Formular ID generiert aus SLICE ID
$form_required               = '&nbsp;<strong class="reqfield inactive">*</strong>'; // Markierung von Pflichtfeldern
$form_bcc                    = "REX_VALUE[11]"; // BCC-Feld
$form_deliver_org            = "REX_VALUE[13]"; //Original senden an Bestätigungsmail anhängen
$form_submit_title           = "REX_VALUE[7]"; // Bezeichnung des Sende-Buttons
$form_attachment             = rex_path::media(). "REX_MEDIA[id=1 output=1]"; // Pfad zum Dateianhang bei Bestätigungs-E-Mail
$form_upload_folder	     = rex_path::media(). "upload/"; // Pfad für Dateien, die über das Formular hochgeladen werden
$form_send_path              = false; // true, wenn der Pfad zum Anhang mitgesendet werden soll
// FROMMODE: true entspricht der Absender der E-Mail dem Empfänger der Mail
// Bei false wird der Absender aus den PHPMailer-Addon-Einstellungen übernommen
$form_from_mode              = true; // Standard=true umgeht Spamfilter
// Welche Felder sollen nicht in der E-Mail  übertragen werden?
$form_ignore_fields          = array(
    'captcha',
    'sicherheitscode',
    'ilink',
    'link',
    'divstart',
    'divend',
    'fieldend',
    'info',
    'exlink'
);
//  Captcha
$captchaID                   = 000; // ID zum Captcha-Artikel der das Captcha-Template nutzt
$captchasource               = htmlspecialchars(rex_getUrl($captchaID));
// Alternative: Externe Einbindung eines Captchas
// $captchasource="/redaxo/captcha/captcha.php";
// Fehlermeldungen / Mehrsprachig
// Sprache 0 -- Hier Deutsch
if (rex_clang::getCurrentId() == 1) {
    //### Achtung! Hinter <<< EOD darf kein Leerzeichen stehen.
    $form_error   = <<<EOD
Leider konnten wir Ihre Anfrage nicht bearbeiten. <br /> Bitte überprüfen Sie Ihre Eingaben.
EOD;
    $form_iban_info = <<<EOD
<br/> Zu Ihrer Sicherheit wurde die IBAN anonymisiert. <br/>
EOD;
    $form_iban_info = <<<EOD
\n Zu Ihrer Sicherheit wurde die IBAN anonymisiert. \n
EOD;
    $form_notice_reload     = "<br />Sie haben versucht die Seite neu zu laden. <br />Ihre Nachricht wurde bereits verschickt";
}
// Sprache 1 -- z.B. Englisch
if (rex_clang::getCurrentId() == 2) {
    $form_error = <<<EOD
Unfortunately we have been unable to process your request. <br/>
Please check the information you have provided.
EOD;
    $form_notice_reload   = "<br />You have tried to reload this page. Your message has already been sent.";
}
// Sprache 2 -- z.B. Niederlande
if (rex_clang::getCurrentId() == 3) {
    $form_error = <<<EOD
We konden uw aanvraag helaas niet verwerken.<br/>
Controleer uw gegevens.
EOD;
    $form_notice_reload   = "<br />You have tried to reload this page. Your message has been already sent.";
}
// E-Mail-HEADER
$form_template_html       = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="de" lang="de">
<head>
<meta http-equiv="Content-Type" content="text/html; charset="UTF-8" />
<title>NACHRICHTEN-ÜBERMITTLUNG</title>
<style type="text/css">
<!--
body {
        font-family: Arial, Helvetica, sans-serif;
        font-size: 16px;
        color: #000;
        line-height: 1em;
        background-color: #F9F9F9;
}
h1 { color: #003366;
        background-color: #FFFFCC;
        display: block;
        clear: both;
        font-size: 20px;
        }
h2 { color: #2B84C6;
        border-bottom-width: 1px;
        border-bottom-style: solid;
        border-bottom-color: #999999;
        display: block;
        clear: both;
        font-size: 20px;
        }
 
.dfheader {
        border-top-width: 10px;
        border-top-style: solid;
        border-top-color: #38393A;
        color: #FFFFFF;
        background-color: #2B84C6;
        font-size: 22px; 
        text-align: center;
        margin: 0px;
        padding: 5px;
}
.slabel {
        display: block;
        margin-right: 5px;
        color: #000
        font-weight: bold;
        margin-top: 1em;
        margin-bottom: 1em;
        background-color: #F9F8D5;
        padding: 4px; 
        
}
br {
        clear: both;
        display: block;
}
-->
</style>
 
</head>
<body>
<div class="dfheader">
  ' . $form_subject . '
</div><br/>
';
// E-Mail-Footer
$form_template_html_footer = '<hr size="1" /><br />
<br /></body></html>';
$nonhtmlfooter    = "\n----------------------------------\n
 ";
// Ende der allgemeinen Konfiguration

$sselect      = $absendermail = "";
$cupload      = 0;
$fcounter     = $xcounter = 1;


if (!function_exists('is_old_android')) {
    function is_old_android($version = '4.2.0')
    {
        
        if (strstr($_SERVER['HTTP_USER_AGENT'], 'Android')) {
            
            preg_match('/Android (\d+(?:\.\d+)+)[;)]/', $_SERVER['HTTP_USER_AGENT'], $matches);
            
            return version_compare($matches[1], $version, '<=');
            
        }
        
    }
}


/**
 * prueft ob die Mindestanzahl an Argumenten mit der Vorgabe uebereinstimmt
 * 
 * Achtung! Die Mindestanzahl an Elementen muss mit Array-Zaehlweise angegeben werden.
 * D.h., die Zahlung beginnt inkl. der Null.
 * 
 * @param int     $mustHave - Mindestanzahl an Elementen 
 * @param array   $elements - Elementa-Array
 * @param string  $formelement - Name des Elementes in dem der Check ausgefuehrt wird
 * @return string
 */
 

if (!function_exists('form_checkElements')) {
    function form_checkElements($mustHave, $elements, $formelement)
    {
        global $REX;
        // Diese Information ist nur im Backend zu sehen
        if (rex::isBackend()) {
            // $formelement darf nicht leer sein
            if ($formelement == '') {
                return 'Der Formelementename wurde nicht erkannt. Siehe Funktion "form_checkElements"<br />';
            }
            // $mustHave muss mind. 2 sein
            if ((int) $mustHave < 2) {
                return $formelement . ': Die Vorgabezahl darf nicht kleiner als 2 sein!<br />';
            }
            // $elements muss ein Array sein
            if (!is_array($elements)) {
                return $formelement . ': Das ubergebene Element ist kein Array.<br />';
            }
            $anzahlElemente = count($elements);
            if ($mustHave > count($elements)) {
                $fehlermeldung = 'Es wurden nicht genuegend Argumente fuer das Formualarfeld "' . $formelement . '" angegeben.<br />';
                $fehlermeldung .= 'Angegeben wurden ' . $anzahlElemente . ' Argumente, benoetigt werden aber mind. ' . $mustHave . ' Argumente!<br />' . "\n";
                return $fehlermeldung;
            } else {
                return '';
            }
        } else {
            return '';
        }
    }
}
/**
 * Gibt eine Fehlermeldung vom Upload zurueck
 * 
 * @param $error_code
 * @see http://de.php.net/manual/en/features.file-upload.errors.php
 * @return string   Fehlermeldung
 */
if (!function_exists('file_upload_error_message')) {
    function file_upload_error_message($error_code)
    {
        switch ($error_code) {
            case UPLOAD_ERR_INI_SIZE: // Fehler Nr.: 1
                return 'The uploaded file exceeds the upload_max_filesize directive in php.ini';
            case UPLOAD_ERR_FORM_SIZE: // Fehler Nr.: 2
                return 'The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form';
            case UPLOAD_ERR_PARTIAL: // Fehler Nr.: 3
                return 'The uploaded file was only partially uploaded';
            case UPLOAD_ERR_NO_FILE: // Fehler Nr.: 4
                return 'No file was uploaded';
            case UPLOAD_ERR_NO_TMP_DIR: // Fehler Nr.: 6 (Introduced in PHP 4.3.10 and PHP 5.0.3.)
                return 'Missing a temporary folder';
            case UPLOAD_ERR_CANT_WRITE: // Fehler Nr.: 7 (Introduced in PHP 5.1.0.)
                return 'Failed to write file to disk';
            case UPLOAD_ERR_EXTENSION: // Fehler Nr.: 8 (Introduced in PHP 5.2.0.)
                return 'File upload stopped by extension';
            default:
                return 'Unknown upload error';
        }
    }
}



if (!function_exists('getValidIban')) {
    function getValidIban($iban)
    {
        // normalize
        $iban    = str_replace(array(
            ' ',
            '-',
            '.',
            ','
        ), '', strtoupper($iban));
        // define the pattern
        $pattern = '#(?P<value>((?=[0-9A-Z]{28}$)AL\d{10}[0-9A-Z]{16}$|^(?=[0-9A-Z]{24}$)AD\d{10}[0-9A-Z]{12}$|^(?=[0-9A-Z]{20}$)AT\d{18}$|^(?=[0-9A-Z]{22}$)BH\d{2}[A-Z]{4}[0-9A-Z]{14}$|^(?=[0-9A-Z]{16}$)BE\d{14}$|^(?=[0-9A-Z]{20}$)BA\d{18}$|^(?=[0-9A-Z]{22}$)BG\d{2}[A-Z]{4}\d{6}[0-9A-Z]{8}$|^(?=[0-9A-Z]{21}$)HR\d{19}$|^(?=[0-9A-Z]{28}$)CY\d{10}[0-9A-Z]{16}$|^(?=[0-9A-Z]{24}$)CZ\d{22}$|^(?=[0-9A-Z]{18}$)DK\d{16}$|^FO\d{16}$|^GL\d{16}$|^(?=[0-9A-Z]{28}$)DO\d{2}[0-9A-Z]{4}\d{20}$|^(?=[0-9A-Z]{20}$)EE\d{18}$|^(?=[0-9A-Z]{18}$)FI\d{16}$|^(?=[0-9A-Z]{27}$)FR\d{12}[0-9A-Z]{11}\d{2}$|^(?=[0-9A-Z]{22}$)GE\d{2}[A-Z]{2}\d{16}$|^(?=[0-9A-Z]{22}$)DE\d{20}$|^(?=[0-9A-Z]{23}$)GI\d{2}[A-Z]{4}[0-9A-Z]{15}$|^(?=[0-9A-Z]{27}$)GR\d{9}[0-9A-Z]{16}$|^(?=[0-9A-Z]{28}$)HU\d{26}$|^(?=[0-9A-Z]{26}$)IS\d{24}$|^(?=[0-9A-Z]{22}$)IE\d{2}[A-Z]{4}\d{14}$|^(?=[0-9A-Z]{23}$)IL\d{21}$|^(?=[0-9A-Z]{27}$)IT\d{2}[A-Z]\d{10}[0-9A-Z]{12}$|^(?=[0-9A-Z]{20}$)[A-Z]{2}\d{5}[0-9A-Z]{13}$|^(?=[0-9A-Z]{30}$)KW\d{2}[A-Z]{4}22!$|^(?=[0-9A-Z]{21}$)LV\d{2}[A-Z]{4}[0-9A-Z]{13}$|^(?=[0-9A-Z]{,28}$)LB\d{6}[0-9A-Z]{20}$|^(?=[0-9A-Z]{21}$)LI\d{7}[0-9A-Z]{12}$|^(?=[0-9A-Z]{20}$)LT\d{18}$|^(?=[0-9A-Z]{20}$)LU\d{5}[0-9A-Z]{13}$|^(?=[0-9A-Z]{19}$)MK\d{5}[0-9A-Z]{10}\d{2}$|^(?=[0-9A-Z]{31}$)MT\d{2}[A-Z]{4}\d{5}[0-9A-Z]{18}$|^(?=[0-9A-Z]{27}$)MR13\d{23}$|^(?=[0-9A-Z]{30}$)MU\d{2}[A-Z]{4}\d{19}[A-Z]{3}$|^(?=[0-9A-Z]{27}$)MC\d{12}[0-9A-Z]{11}\d{2}$|^(?=[0-9A-Z]{22}$)ME\d{20}$|^(?=[0-9A-Z]{18}$)NL\d{2}[A-Z]{4}\d{10}$|^(?=[0-9A-Z]{15}$)NO\d{13}$|^(?=[0-9A-Z]{28}$)PL\d{10}[0-9A-Z]{,16}n$|^(?=[0-9A-Z]{25}$)PT\d{23}$|^(?=[0-9A-Z]{24}$)RO\d{2}[A-Z]{4}[0-9A-Z]{16}$|^(?=[0-9A-Z]{27}$)SM\d{2}[A-Z]\d{10}[0-9A-Z]{12}$|^(?=[0-9A-Z]{,24}$)SA\d{4}[0-9A-Z]{18}$|^(?=[0-9A-Z]{22}$)RS\d{20}$|^(?=[0-9A-Z]{24}$)SK\d{22}$|^(?=[0-9A-Z]{19}$)SI\d{17}$|^(?=[0-9A-Z]{24}$)ES\d{22}$|^(?=[0-9A-Z]{24}$)SE\d{22}$|^(?=[0-9A-Z]{21}$)CH\d{7}[0-9A-Z]{12}$|^(?=[0-9A-Z]{24}$)TN59\d{20}$|^(?=[0-9A-Z]{26}$)TR\d{7}[0-9A-Z]{17}$|^(?=[0-9A-Z]{,23}$)AE\d{21}$|^(?=[0-9A-Z]{22}$)GB\d{2}[A-Z]{4}\d{14}))#';
        // check
        if (preg_match($pattern, $iban, $matches)) {
            return true;
        } else {
            return false;
        }
    }
}
if (!function_exists('convertBytes')) {
    function convertBytes($value)
    {
        if (is_numeric($value)) {
            return $value;
        } else {
            $value        = trim($value);
            $value_length = strlen($value);
            $qty          = substr($value, 0, $value_length - 1);
            $unit         = strtolower(substr($value, $value_length - 1));
            switch ($unit) {
                case 'g':
                    $qty *= 1024;
                case 'm':
                    $qty *= 1024;
                case 'k':
                    $qty *= 1024;
                case 'b':
                    $qty = $qty;
            }
            return $qty;
        }
    }
}
//### Achtung! Hinter <<< End darf kein Leerzeichen stehen.
$rex_form_data = <<<End
REX_VALUE[id=3]
End;

$rex_form_data = trim(str_replace("<br />","",rex_yform::unhtmlentities($rex_form_data)));

//### Achtung! Hinter <<< End darf kein Leerzeichen stehen.
$mailbody      = <<<End
End;
$responsemail  = <<<End
REX_VALUE[5]
End;
if (isset($_POST['eingabe'])) {
    $eingabe = $_POST['eingabe'];
}
$FORM    = array();
$FORM          = rex_request::post('FORM', 'array');
$formoutput    = array();
$warning       = array();
$warnblock       = array();
$warning_set   = 0; // wird zu 1, wenn ein Fehler auftritt
$form_elements = array();
$form_elements = explode("\n", $rex_form_data);
//Abfrage Felder Vor- und Nachname, 14.05.2014, Benedikt Marcard, Marcard Media, www.marcard-media.de
for ($i = 0; $i < count($form_elements); $i++) {
	
	 if (!isset($FORM[$form_ID]['el_' . $i])) {
        $FORM[$form_ID]['el_' . $i] = '';
    }
    if (!isset($FORM[$form_ID][$form_ID . 'send'])) {
        $FORM[$form_ID][$form_ID . 'send'] = '';
    }
    if (!isset($warning["el_" . $i])) {
        $warning["el_" . $i] = NULL;
    }
    
    if (!isset($warnblock["el_" . $i])) {
        $warnblock["el_" . $i] = NULL;
    }
    $element = explode("|", $form_elements[$i]);
    switch ($element[1]) {
        case ("Nachname"):
            $responsemail = str_replace("%Nachname%", $FORM[$form_ID]['el_' . $i], $responsemail);
            break;
        case ("Vorname"):
            $responsemail = str_replace("%Vorname%", $FORM[$form_ID]['el_' . $i], $responsemail);
            break;
        case ("Anrede"):
            if ($FORM[$form_ID]['el_' . $i] == 'Herr') {
                $responsemail = str_replace("%Anrede%", 'Sehr geehrter ' . $FORM[$form_ID]['el_' . $i] . '', $responsemail);
            }
            if ($FORM[$form_ID]['el_' . $i] == 'Frau') {
                $responsemail = str_replace("%Anrede%", 'Sehr geehrte ' . $FORM[$form_ID]['el_' . $i] . '', $responsemail);
            }
            break;
    }
}
$responder     = "REX_VALUE[10]";
$form_DATE                   = date("d.m.Y"); // Datum
$form_TIME                   = date("H:i"); // TIME
$form_elements = explode("\n", $rex_form_data);
$responsemail  = str_replace("%Datum%", $form_DATE, $responsemail);
$responsemail  = str_replace("%Zeit%", $form_TIME, $responsemail);
//Adresse die als Absenderadresse der Bestätigungs-E-Mail eingegeben wurde
$responsemail  = str_replace("%Absender%", "REX_VALUE[2]", $responsemail);
//Empfänderadresse die im Modul angegeben wurde
$responsemail  = str_replace("%Mail%", "REX_VALUE[1]", $responsemail);
$responsemail  = str_replace("%Betreff%", "REX_VALUE[4]", $responsemail);
$token         = md5(uniqid('token'));
$formcaptcha   = null;
$dfreload      = null;
$mailbodyhtml  = '';
$form_enctype  = '';
/**
 * Enthaelt die Dateiangaben der uebertragenen Datei und den Namen der Zieldatei
 * Form: array ( targetFile => tempFile )
 * @var array
 */
$upload_File   = array();
for ($i = 0; $i < count($form_elements); $i++) {
    // ueberspringe Leerzeilen
    if (trim($form_elements[$i]) == '') {
        continue;
    }
    $element   = explode("|", $form_elements[$i]);
    $AFE[$i]   = $element;
    $formfield = 0;
   
    
    switch ($element[0]) {
        case "svar":
        case "session":
            $formoutput[] = '
          <input type="hidden" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '" value="' . $_SESSION["REX_VALUE[16]"] . '" />';
            break;
        //  Gestaltungselemente
        case "headline":
            $formoutput[] = '<div class="formheadline">' . $element[1] . '<input type="hidden" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '" value="' . $element[1] . '"/></div>';
            break;
        case "info":
            $formoutput[] = '<div class="formhinweis">' . $element[1] . '<input type="hidden" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '" value="' . $element[1] . '"/></div>';
            break;
        case "HTML":
	case "html":
            $formoutput[] = '<div class="formhtml">' . $element[1] . '</div>';
            break;
        case "exlink":
            $formoutput[] = '<div class="formlink"><a href="' . $element[1] . '" onclick="window.open(this.href); return false;">' . $element[2] . '</a></div>';
            break;
        case "ilink":
        case "link":    
            if ($element[3] != "") {
                $linkclass = 'class="' . $element[3] . '" ';
            } else {
                $linkclass = "";
            }
            $formoutput[] = '<div class="formlink"><a ' . $linkclass . 'href="' . rex_getUrl($element[1]) . $element[2] . '">' . $element[4] . '</a></div>';
            break;
        case "trennelement":
        case "divider":
            $formoutput[] = '<div class="formtrenn"></div>';
            break;
        case "fieldstart":
            $formoutput[] = '<fieldset class="fieldset"><legend>' . $element[1] . '</legend><input type="hidden" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '" value="' . $element[1] . '"/>';
            $formfield    = "on";
            break;
        case "fieldend":
            $formoutput[] = '</fieldset>';
            $formfield    = "on";
            break;
        case "divstart":
            $str   = $element[1];
            $first = $str[0];
            $id    = str_replace("#", '', $str);
            if (!isset($element[2]))
                $element[2] = ''; // Zeile eingefügt - ### MW ###
            if ($first == '#') {
                $formoutput[] = '<div id="' . $id . '">' . $element[2];
            } else {
                $formoutput[] = '<div class="' . $element[1] . '">' . $element[2];
            }
            $formfield = "on";
            break;
        case "divend":
            $formoutput[] = '</div>';
            $formfield    = "on";
            break;
        // Formular-Felder 
        case "checkbox":
            $req      = '';
            $cchecked = "";
            if (isset($element[2]) && $element[2] == 1) {
                $req = $form_required;
            }
            if (!isset($element[3]))
                $element[3] = ''; // Zeile eingefügt - ### MW ###
            if ((trim($FORM[$form_ID]["el_" . $i]) == "X") || ($FORM[$form_ID]["el_" . $i] == '' && !$FORM[$form_ID][$form_ID . "send"] && $element[3] == 1)) {
                $cchecked = ' checked="checked"';
                $hidden   = "";
            } else {
                $cchecked = '';
                //$hidden = '<div><input type="hidden" name="FORM['.$form_ID.'][el_'.$i.']" value="0" /></div>';
                $hidden   = "";
            }
            if (isset($element[2]) && $element[2] == 1 && $cchecked == "" && $FORM[$form_ID][$form_ID . "send"]) {
                $warning["el_" . $i]   = $form_warn_css;
                $warnblock["el_" . $i] = $form_warnblock_css;
                $e                     = 1;
                $warning_set           = 1;
            }
            $formoutput[] = $hidden . '
              <div class="'.$form_field_wrp.' ' . $warnblock["el_" . $i] . '"> <span class="checkspan"><label ' . $warning["el_" . $i] . ' for="el_' . $i . '" >' . $element[1] . $req . '</label>
                <input type="checkbox" title="' . $element[4] . '" class="formcheck" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '"value="X" ' . $cchecked . ' /></span></div>';
            break;
        // Radio-Buttons von Markus Feustel 07.01.2008
        case "radio":
            $req = '';
            if (isset($element[2]) && $element[2] == 1) {
                $req = $form_required;
            }
            if ((trim($FORM[$form_ID]["el_" . $i]) == 1) || ($FORM[$form_ID]["el_" . $i] == '' && !$FORM[$form_ID][$form_ID . "send"] && $element[3] == 1)) {
                $checked = ' checked="checked"';
                $hidden  = '';
            } else {
                $checked = "";
                $hidden  = '<input type="hidden" name="FORM[' . $form_ID . '][el_' . $i . ']" value="0" />';
            }
            if (trim($FORM[$form_ID]["el_" . $i]) == '' && trim($element[5]) != '') {
                $FORM[$form_ID]["el_" . $i] = trim($element[5]);
            }
            if (isset($element[2]) && $element[2] == 1 && trim($FORM[$form_ID]["el_" . $i]) == "" && $FORM[$form_ID][$form_ID . "send"] == 1) {
                $warning["el_" . $i]   = $form_warn_css;
                $warnblock["el_" . $i] = $form_warnblock_css;
                $warning_set           = 1;
                $e                     = 1;
            }
            $ro            = explode(';', trim($element[3]));
            $val           = explode(';', trim($element[4]));
            $formlabel[$i] = '<label ' . $warning["el_" . $i] . ' for="el_' . $i . '" >' . $element[1] . $req . '</label>';
            $fo            = $formlabel[$i] . '<div id="el_' . $i . '" >' . "\n";
            for ($xi = 0; $xi < count($ro); $xi++) {
                if ($val[$xi] == trim($FORM[$form_ID]["el_" . $i])) {
                    $checked = ' checked="checked"';
                } else {
                    $checked = '';
                }
                $fo .= '<div class="radiofield"><input type="radio" class="formradio" name="FORM[' . $form_ID . '][el_' . $i . ']" id="r' . $i . '_Rel_' . $xi . '" value="' . $val[$xi] . '" ' . $checked . ' />' . "\n";
                $fo .= '<label class="radiolabel" ' . $warning["el_" . $i] . 'for="r' . $i . '_Rel_' . $xi . '" >' . $ro[$xi] . '</label></div>' . "\n";
            }
            $fo .= '</div>' . "\n";
            $formoutput[$i] = '<div class="'.$form_field_wrp.' radioblock' . $warnblock["el_" . $i] . '">' . $fo . '</div>';
            break;
        //  Ende Radio-Buttons
        case "hidden":
        case "password":
        case "text":
        case "email":
        case "url":
        case "date":
        case "time":
        case "IBAN":
        case "BIC":
        case "subject":
            $req  = '';
            $freq = '';
            if (isset($element[2]) && $element[2] == 1) {
                $req  = $form_required;
                $freq = ' required';
            }
            // 14.08.2009: GET-VARIABLENABFRAGE von Tito übernommen, siehe http://forum.redaxo.de/ftopic11635-30.html
            if ($FORM[$form_ID]["el_" . $i] == '' && !$FORM[$form_ID][$form_ID . 'send'] && isset($element[3])) // " && isset($element[3])" eingefügt - ### MW ###
                {
                if (strchr($element[3], 'GET_')) {
                    $get        = explode('GET_', $element[3]);
                    $element[3] = rex_get($get[1]);
                }
                
                if ($element[3] == "session") {
                    $element[3] = $_SESSION["REX_VALUE[16]"];
                    unset($_SESSION["REX_VALUE[16]"]);
                }
                if ($element[3] == "today") {
                    $element[3] = $form_DATE;
                }
                if ($element[3] == "now") {
                    $element[3] = $form_TIME;
                }
                
                $FORM[$form_ID]["el_" . $i] = trim($element[3]);
            }
            if (isset($element[2]) && $element[2] == 1 && (trim($FORM[$form_ID]["el_" . $i]) == "" || trim($FORM[$form_ID]["el_" . $i]) == trim($element[3])) && $FORM[$form_ID][$form_ID . "send"] == 1) {
                $warning["el_" . $i]   = $form_warn_css;
                $warnblock["el_" . $i] = $form_warnblock_css;
                $warning_set           = 1;
            }
            // ### Validierung falls Pflichtelement oder Inhalt da und Formular abgeschickt
            if (!isset($element[5]))
                $element[5] = ''; // Zeile eingefügt - ### MW ###
            if ((isset($element[2]) && $element[2] == 1) && (trim($FORM[$form_ID]["el_" . $i]) != "") && ($FORM[$form_ID][$form_ID . "send"] == 1) || (trim($element[5]) != "" && $FORM[$form_ID][$form_ID . "send"] == 1 && $element[2] != 1 && trim($FORM[$form_ID]["el_" . $i]) != "")) {
                // checken, ob und welches Validierungsmodell gewaehlt
                if (trim($element[5]) != '') {
                    // falls Validierung gefordert
                    $valid_ok = TRUE;
                    $inhalt   = trim($FORM[$form_ID]["el_" . $i]);
                    switch (trim($element[5])) {
                        case "mail":
                            if (!preg_match("#^.+@(.+\.)+([a-zA-Z]{2,6})$#", $inhalt))
                                $valid_ok = FALSE;
                            break;
                        case "sender":
                        case "sendercheck":
                        case "absendermail":
                            if (!preg_match("#^.+@(.+\.)+([a-zA-Z]{2,6})$#", $inhalt)) {
                                $valid_ok = FALSE;
                            } else {
                                $absendermail = $inhalt;
                                $responsemail  = str_replace("%Usermail%", $absendermail, $responsemail);
                                $responsemail  = str_replace("%Besuchermail%", $absendermail, $responsemail);
                                // Neu: 14.01.2014 - Sender als Checkfield
                                if ($element[5] == "sendercheck") {
                                    $_SESSION["formcheck"] = $inhalt;
                                }
                            }
                            break;
                        case "tel":
                        case "telefon":
                            if (preg_match("#^[ \(\)\+0-9\/-]{6,}+$#", $inhalt)) {
                                break;
                            } else {
                                $valid_ok = FALSE;
                            }
                            break;
                        case "plz":
                            if (preg_match("/^[0-9]{5}$/", $inhalt)) {
                                break;
                            } else {
                                $valid_ok = FALSE;
                            }
                            break;
                        case "plz4":
                            if (preg_match("/^[0-9]{4}$/", $inhalt)) {
                                break;
                            } else {
                                $valid_ok = FALSE;
                            }
                            break;
                        case "name":
                            if (preg_match("/^[^;,@%:_#+*'!\"§$\/()=?]+$/i", $inhalt)) {
                                break;
                            } else {
                                $valid_ok = FALSE;
                            }
                            break;
                        case "digit":
                            if (!ctype_digit($inhalt))
                                $valid_ok = FALSE;
                            break;
                        case "alpha":
                            if (!ctype_alpha($inhalt))
                                $valid_ok = FALSE;
                            break;
                        case "url":
                            $inhalt = trim($inhalt);
                            if (preg_match("#^(http|https|ftp)+(://www.)+([a-z0-9-_.]{2,}\.[a-z]{2,4})$#i", $inhalt)) {
                                break;
                            } else {
                                $valid_ok = FALSE;
                                break;
                            }
                            break;
                        case "iban":
                            if (($validiban = getValidIban($inhalt))) {
                                break;
                            } else {
                                $valid_ok = FALSE;
                                break;
                            }
                            break;
                        case "date":
                            if (strpos($inhalt, '.')) {
                                $values = explode('.', $inhalt);
                                $day    = $values[0];
                                $month  = $values[1];
                                $year   = $values[2];
                                if ($check = checkdate($month, $day, $year)) {
                                    break;
                                } else {
                                    $valid_ok = FALSE;
                                    break;
                                }
                            } else {
                                $valid_ok = FALSE;
                                break;
                            }
                            break;
                        case "time":
                            if (!(bool) preg_match('/^(?:2[0-3]||(([0-9]||0[0-9])||1[0-9])):[0-5][0-9]$/', trim($inhalt))) {
                                $valid_ok = FALSE;
                                break;
                            }
                            break;
                        case "bic":
                            if (preg_match("#^[a-zA-Z]{6}[a-zA-Z0-9]{2,5}$#", $inhalt)) {
                                break;
                            } else {
                                $valid_ok = FALSE;
                            }
                            break;
                        case "checkfield":
                            if (preg_match("/[\w\p{L}]/u", $inhalt)) {
                                $_SESSION["formcheck"] = $inhalt;
                                break;
                            } else {
                                $valid_ok = FALSE;
                            }
                            break;
                        // Captchaabfrage
                        case "check":
                        case "captcha":
                            if (isset($_SESSION['token'])) {
                                if ($_SESSION['token'] == rex_request::post('token')) {
                                    $formcaptcha = 'off';
                                    $valid_ok    = FALSE;
                                    $dfreload    = $form_notice_reload;
                                    break;
                                }
                            }
                            if ($_SESSION["formcheck"] == $inhalt) {
                                $valid_ok = TRUE;
                                break;
                            } else {
                                $formcaptcha = 'off';
                                $valid_ok    = FALSE;
                                break;
                            }
                    } // switch (trim($element[5]))
                    if (!$valid_ok) {
                        $warning["el_" . $i]   = $form_warn_css;
                        $warnblock["el_" . $i] = $form_warnblock_css;
                        $warning_set           = 1;
                    }
                } // falls Validierung gefordert
            }
            $placeholder = '';
            // ### /Validierung
            if ($element[0] == "hidden") {
                $inptype = "hidden";
            }
            if ($element[0] == "BIC") {
                $placeholder = ' placeholder="Bitte BIC eingeben"';
                $inptype     = "text";
            }
            if ($element[0] == "IBAN") {
                $placeholder = ' placeholder="Bitte IBAN eingeben"';
                $inptype     = "text";
            }
            if ($element[0] == "date") {
                $placeholder = ' placeholder="tt.mm.jjjj"';
                if (is_old_android()) {
                    $inptype = "text";
                } else {
                    $inptype = "date";
                }
            }
            if ($element[0] == "time") {
                $placeholder = ' placeholder="hh:mm"';
                $inptype     = "time";
            }
            if ($element[0] == "text") {
                $inptype = "text";
            }
            if ($element[0] == "password") {
                $inptype = "password";
            }
            if ($element[0] == "email") {
                $placeholder = ' placeholder="name@domain.de"';
                $inptype     = "email";
            }
            if ($element[0] == "url") {
                $inptype = "url";
            }
            if ($formcaptcha == 'off') {
                if ($inptype == 'hidden') {
                    $formoutput[] = '
                <input type="' . $inptype . '" class="formtext ' . $element[0] . '" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '" value="" />';
                } else {
                    $formoutput[] = '
                   <div class="'.$form_field_wrp.' ' . $warnblock["el_" . $i] . '"> <label ' . $warning["el_" . $i] . ' for="el_' . $i . '" >' . $element[1] . $req . '</label>
                    <input type="' . $inptype . '" class="formtext" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '" value="" ' . $freq . ' /></div>
                    ';
                }
                $formcaptcha = 'on';
            } else {
                $formoutput[] = '
                 <div class="'.$form_field_wrp.' ' . $warnblock["el_" . $i] . '">   <label ' . $warning["el_" . $i] . ' for="el_' . $i . '" >' . $element[1] . $req . '</label>
                    <input type="' . $inptype . '" ' . $placeholder . ' class="formtext f' . $element[0] . '" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '" value="' . htmlspecialchars(stripslashes($FORM[$form_ID]["el_" . $i])) . '" ' . $freq . ' /></div>
                    ';
            }
            break;
        case "textarea":
            $req                = '';
            $freq               = '';
            $fehlerImFormaufbau = form_checkElements(2, $element, 'textarea');
            if (isset($element[2]) && $element[2] == 1) {
                $req  = $form_required;
                $freq = ' required';
            }
            if (isset($element[3]) && $FORM[$form_ID]["el_" . $i] == '' && !$FORM[$form_ID][$form_ID . "send"]) {
                $FORM[$form_ID]["el_" . $i] = $element[3];
            }
            if (isset($element[2]) && isset($element[3]) && $element[2] == 1 && (trim($FORM[$form_ID]["el_" . $i]) == "" || trim($FORM[$form_ID]["el_" . $i]) == trim($element[3])) && $FORM[$form_ID][$form_ID . "send"] == 1) {
                $warning["el_" . $i]   = $form_warn_css;
                $warnblock["el_" . $i] = $form_warnblock_css;
                $warning_set           = 1;
            }
            $formoutput[] = $fehlerImFormaufbau . '
         <div class="'.$form_field_wrp.' ' . $warnblock["el_" . $i] . '">  <label ' . $warning["el_" . $i] . ' for="el_' . $i . '" >' . $element[1] . $req . '</label>
           <textarea class="formtextfield" cols="40" rows="10" title="' . $element[1] . '" name="FORM[' . $form_ID . '][el_' . $i . ']" id="el_' . $i . '"' . $freq . ' >'.htmlspecialchars(stripslashes($FORM[$form_ID]["el_" . $i])).'</textarea></div>';
            break;
        case "select":
        case "subjectselect":
            $req                = '';
            $fehlerImFormaufbau = form_checkElements(3, $element, 'select');
            if (isset($element[2]) && $element[2] == 1) {
                $req = $form_required;
            }
            $SEL = new rex_select();
            $SEL->setName("FORM[" . $form_ID . "][el_" . $i . "]");
            $SEL->setId("el_" . $i);
            $SEL->setSize(1);
            $SEL->setStyle(' class="formselect"');
            if ($FORM[$form_ID]["el_" . $i] == "" && !$FORM[$form_ID][$form_ID . "send"]) {
                $SEL->setSelected($element[3]);
            } else {
                $SEL->setSelected($FORM[$form_ID]["el_" . $i]);
            }
            foreach (explode(";", trim($element[4])) as $v) {
                $SEL->addOption($v, $v);
            }
            if (isset($element[2]) && $element[2] == 1 && trim($FORM[$form_ID]["el_" . $i]) == "" && $FORM[$form_ID][$form_ID . "send"] == 1) {
                $warning["el_" . $i]   = $form_warn_css;
                $warnblock["el_" . $i] = $form_warnblock_css;
                $warning_set           = 1;
            }
            $formoutput[] = $fehlerImFormaufbau . '
             <div class="'.$form_field_wrp.' ' . $warnblock["el_" . $i] . '"> <label ' . $warning["el_" . $i] . ' for="el_' . $i . '" >' . $element[1] . $req . '</label>
              ' . $SEL->get() . '</div>';
            break;
      
       
        // Upload
        case "upload":
            $fehlerImFormaufbau         = form_checkElements(5, $element, 'Upload');
            $req                        = '';
            $error_message              = '';
            // wird true, wenn keine Datei uebergeben wurde
            $upload_keineDateivorhanden = false;
            if (isset($element[2]) && $element[2] == 1) {
                $req = $form_required;
            }
            if (isset($element[6]) && trim($element[6]) != '') {
                $upload_MaxSice = trim($element[6]);
            } else {
                $upload_MaxSice = 0;
            }
            if (!empty($_FILES)) {
                if ($_FILES['FORM']['error'][$form_ID]['el_' . $i] === UPLOAD_ERR_OK) {
                    // upload ok
                } elseif ($req == '' && $_FILES['FORM']['error'][$form_ID]['el_' . $i] === UPLOAD_ERR_NO_FILE) {
                    // upload ok aber keine Datei vorhanden
                    $upload_keineDateivorhanden = true;
                } else {
                    $error_message .= file_upload_error_message($_FILES['FORM']['error'][$form_ID]['el_' . $i]);
                    $warning["el_" . $i]   = $form_warn_css;
                    $warnblock["el_" . $i] = $form_warnblock_css;
                    $warning_set           = 1;
                }
                // alexplus: http://forum.redaxo.de/ftopic11635-150.html          
                if (!$upload_keineDateivorhanden && $error_message == '') {
                    $targetPath     = $form_upload_folder;
                    $tempFile       = $_FILES['FORM']['tmp_name'][$form_ID]['el_' . $i];
                    $preTarget      = time() . "_" . $_FILES['FORM']['name'][$form_ID]['el_' . $i];
                    // Leerzeichen ersetzen durch _
                    $targetFile     = str_replace(" ", "_", $preTarget);
                    $targetPathFile = str_replace('//', '/', $targetPath) . $targetFile;
                    // Multimail
                    $cupload++;
                    $domailfile[$cupload]           = $targetFile;
                    $upload_Extensions              = array();
                    $upload_Extensions_errormessage = '';
                    $zaehler_element                = count(explode(";", trim($element[4])));
                    $zaehler_element_z              = 0;
                    foreach (explode(";", trim($element[4])) as $v) {
                        if ($v != '') {
                            $upload_Extensions[] = $v;
                            $upload_Extensions_errormessage .= '.' . $v;
                        }
                        $zaehler_element_z++;
                        if ($zaehler_element_z < $zaehler_element) {
                            $upload_Extensions_errormessage .= ' | ';
                        }
                    }
                    $fileParts = pathinfo($_FILES['FORM']['name'][$form_ID]['el_' . $i]);
                    if (isset($fileParts['extension']) and $fileParts['extension'] != '' and in_array($fileParts['extension'], $upload_Extensions)) {
                        $upload_File[$targetPathFile] = $tempFile;
                        $FORM[$form_ID]['el_' . $i]  = ($form_send_path) ? $targetPathFile : $targetFile;
                    } else {
                        // Warnung ueber nicht erlaubte Datei ausgeben
                        $warning["el_" . $i]   = $form_warn_css;
                        $warnblock["el_" . $i] = $form_warnblock_css;
                        $warning_set           = 1;
                        $error_message .= '<div class="forminfo">Die Datei kann nicht hochgeladen werden. Evtl. liegt es an einem falschen Dateityp. Erlaubt ist hier nur: ' . $upload_Extensions_errormessage . '</div>';
                    }
                    if ($_FILES['FORM']['size'][$form_ID]['el_' . $i] < convertBytes($upload_MaxSice)) {
                        // alles ok
                    } else {
                        // Warnung ueber zu grosse Datei ausgeben
                        $warning["el_" . $i]   = $form_warn_css;
                        $warnblock["el_" . $i] = $form_warnblock_css;
                        $warning_set           = 1;
                        $error_message .= 'Die Datei "' . htmlspecialchars($targetFile) . '" ist zu gro&#223;!<br />';
                        $error_message .= 'Erlaubt sind maximal ' . convertBytes($upload_MaxSice) / 1048576 . ' MB';
                    }
                } // if (!$upload_keineDateivorhanden && $error_message == '')
            } // if (!empty($_FILES))
            if (isset($error_message) and $error_message != '') {
                $error_message = '<p>' . $error_message . '</p>';
            } else {
                $error_message = '';
            }
            $form_tmp = '';
            $form_tmp .= $fehlerImFormaufbau;
            $form_tmp .= $error_message;
            $form_tmp .= "\n" . '<div class="'.$form_field_wrp.' ' . $warnblock["el_" . $i] . '"><label ' . $warning["el_" . $i] . ' for="FORM[' . $form_ID . '][el_' . $i . ']" >' . $element[1] . $req . '</label>' . "\n";
            $form_tmp .= '<input type="file" name="FORM[' . $form_ID . '][el_' . $i . ']" id="FORM[' . $form_ID . '][el_' . $i . ']" /></div>' . "\n";
            $formoutput[] = $form_tmp;
            $form_enctype = 'enctype="multipart/form-data"';
            break;
    }
}

// pruefe Pfad auf Vorhandensein und Schreibrechte, Wenn Pfad nicht vorhanden, ignoriere die weitere Verarbeitung.
if (isset($form_upload_folder) and $form_upload_folder != '' and rex::isBackend()) {
    // ... dum die dum ... Pfadpruefung erfolgt hier ...beginnt der Uploadpfad nicht mit einem Slash, muss es sich um einen lokalen Ordner handeln der vom Backend aus erweitert werden muss
    if (substr($form_upload_folder, 0, 1) != '/') {
        $form_upload_folder_tmp = '../' . $form_upload_folder;
    } else {
        $form_upload_folder_tmp = $form_upload_folder;
    }

    if (rex_dir::isWritable($form_upload_folder_tmp) !== true) {
        echo rex_view::warning('Der Uploadpfad "' . $form_upload_folder_tmp . '" ist nicht beschreibbar.<br />
                      Pruefe die Schreibrechte oder lasse die Angaben zum Uploadordner leer, wenn kein Uploadfeld genutzt wird.');
    }
}
// =================AUSGABE-KOPF============================
$out = '
   
   <form class="'.$form_tag_class.'" id="' . $form_ID . '" action="' . rex_getUrl(REX_ARTICLE_ID) . '#doformREX_SLICE_ID" accept-charset="UTF-8" method="post" ' . $form_enctype . '>
      <div><input type="hidden" name="FORM[' . $form_ID . '][' . $form_ID . 'send]" value="1" /><input type="hidden" name="ctype" value="ctype" /></div>
      <input type="hidden" name="token" value="' . $token . '" />';
// =================Formular-generieren=====================
foreach ($formoutput as $fields) {
    $out .= $fields;
}
// =================AUSGABE-FUSS============================
$out .= '
 
 
      <div class="submitblock">
         <input type="submit" name="FORM[' . $form_ID . '][' . $form_ID . 'submit]" value="' . $form_submit_title . '" class="formsubmit" />
      </div>
      </form>
   ';
// =================SEND MAIL===============================
if (isset($FORM[$form_ID][$form_ID . 'send']) && $FORM[$form_ID][$form_ID . 'send'] == 1 && !$warning_set) {
    // BEGIN :: Uploadverarbeitung pruefe Pfad auf Vorhandensein und Schreibrechte
    // Wenn Pfad nicht vorhanden, ignoriere die weitere Verarbeitung.
    if (isset($form_upload_folder) and $form_upload_folder != '' and count($upload_File) > 0) {
        // ... dum die dum ... Pfadpruefung erfolgt hier ...
        foreach ($upload_File as $targetFile => $tempFile) {
            move_uploaded_file($tempFile, $targetFile);
        }
    } // if (isset ($form_upload_folder) and $form_upload_folder != '')
    // END :: Uploadverarbeitung
    $_SESSION['token'] = rex_request::post('token');
   
    // Selbsdefinierte Sessionvariable zurücksetzen 
    if ("REX_VALUE[16]" != "") {
        unset($_SESSION["REX_VALUE[16]"]);
    }
        // E-Mail-Content
    foreach ($FORM[$form_ID] as $k => $v) {
        $matches = array();
        
            // HTML-AUSGABE und Plaintext erstellen
            $key = preg_replace('#el_#', '', $k);
            if ($k != $form_ID . 'submit' && $k != $form_ID . 'send' && (!isset($AFE[$key][5]) || $AFE[$key][5] != 'captcha') && stripslashes($v) != '' && isset($AFE[$key][1]) && !in_array($AFE[$key][0], $form_ignore_fields)) {
                $v  = strip_tags($v);
                $v  = stripslashes($v);
                $v2 = substr($v, 0, -5) . 'XXXXX';
                switch ($AFE[$key][0]) {
                    case "subjectselect":
                        $sselect = $v . ' - ';
                        break;
                    case "BIC":
                        $mailbodyhtml .= '<span class="slabel">' . $fcounter . '. ' . $AFE[$key][1] . ": </span>" . strtoupper($v) . '<br />';
                        $mailbody .= $xcounter . '. ' . $AFE[$key][1] . ": " . strtoupper($v) . "\n";
                        $rmailbodyhtml .= '<span class="slabel">' . $fcounter . '. ' . $AFE[$key][1] . ": </span>" . strtoupper($v) . '<br />';
                        $rmailbody .= $xcounter . '. ' . $AFE[$key][1] . ": " . strtoupper($v) . "\n";
                        $fcounter++;
                        $xcounter++;
                        break;
                    case "IBAN":
                        $rmailbodyhtml .= $form_iban_info . '<span class="slabel">' . $fcounter . '. ' . $AFE[$key][1] . ": </span>" . strtoupper($v2) . '<br />';
                        $rmailbody .= $form_iban_info2 . $xcounter . '. ' . $AFE[$key][1] . ": " . strtoupper($v2) . "\n";
                        $mailbodyhtml .= '<span class="slabel">' . $fcounter . '. ' . $AFE[$key][1] . ": </span>" . strtoupper($v) . '<br />';
                        $mailbody .= $xcounter . '. ' . $AFE[$key][1] . ": " . strtoupper($v) . "\n";
                        $fcounter++;
                        $xcounter++;
                        break;
                    case "fieldstart":
                        $mailbodyhtml .= '<h1>' . $v . '</h1>';
                        $mailbody .= "\n" . '****' . $v . "\n" . '---------------------------------------------------------' . "\n";
                        $rmailbodyhtml .= '<h1>' . $v . '</h1>';
                        $rmailbody .= "\n" . '****' . $v . "\n" . '---------------------------------------------------------' . "\n";
                        break;
                    case "headline":
                        $mailbodyhtml .= '<h2>' . $v . '</h2>';
                        $mailbody .= "\n" . '---' . $v . "\n" . '---------------------------------------------------------' . "\n";
                        $rmailbodyhtml .= '<h2>' . $v . '</h2>';
                        $rmailbody .= "\n" . '---' . $v . "\n" . '---------------------------------------------------------' . "\n";
                        break;
                    case "subject":
                        $mailbodyhtml .= '<span class="slabel">' . $fcounter . '. ' . $AFE[$key][1] . ": </span>" . stripslashes($v) . '<br />';
                        $mailbody .= $xcounter . '. ' . $AFE[$key][1] . ": " . stripslashes($v) . "\n";
                        $subject = "Anfrage zu: " . stripslashes($v);
                        $fcounter++;
                        $xcounter++;
                        break;
                    
                    
                    default:
                        $mailbodyhtml .= '<span class="slabel">' . $fcounter . '. ' . strip_tags($AFE[$key][1]) . ": </span>" . $v . '<br />';
                        $mailbody .= $xcounter . '. ' . strip_tags($AFE[$key][1]) . ": " . $v . "\n";
                        $rmailbodyhtml .= '<span class="slabel">' . $fcounter . '. ' . strip_tags($AFE[$key][1]) . ": </span>" . $v . '<br />';
                        $rmailbody .= $xcounter . '. ' . strip_tags($AFE[$key][1]) . ": " . $v . "\n";
                        $fcounter++;
                        $xcounter++;
                }
            }
        }    
   

$Body =  $form_template_html . nl2br($mailbodyhtml) . $form_template_html_footer;
$To = "REX_VALUE[1]";
$from = $From = "REX_VALUE[1]";

     // E-Mail
    $mail = new rex_mailer(); // Mailer initialisieren
    $mail->CharSet = 'UTF-8'; // Zeichensatz   
    $mail->AddAddress($To); // Empfänger
    if ($absendermail != '') {
        $mail->AddReplyTo($absendermail); // Antwort an Absender per Reply-To -  Besucher
    }
    if ($form_bcc != '') {
        $mail->AddBCC($form_bcc);
    }
    
// Wenn true Daten aus do form! , wenn false aus PHPMailer    
    if ($form_from_mode == true) {
    $mail->From = $From;
    $mail->Sender   = $from ; //Absenderadresse als Return-Path
    $mail->FromName = $from ; // Abdendername entspricht Empfängeradresse 
    }
// Betreff ermitteln
     if ($sselect != "") {
        $mail->Subject = $sselect . "REX_VALUE[4]"; // Betreff subjectselect

    } 
 
    else {
	     $mail->Subject = $subject; // Betreff
           }   
   
   // HTML-EMAIL JA /NEIN
    if ("REX_VALUE[12]" == 'ja') {
        $mail->Body    = $form_template_html . nl2br($mailbodyhtml) . $form_template_html_footer;
        $mail->AltBody = $mailbody . $nonhtmlfooter;
    } else {
        $mail->Body = $mailbody . $nonhtmlfooter;
    }

   
	// Dateianhänge versenden
    if (is_array($domailfile) and "REX_VALUE[15]" == "Ja" and $cupload > "0") {
        foreach ($domailfile as $dfile) {
            $mail->AddAttachment($form_upload_folder.$dfile);
        }
    }
    if (!function_exists('doppelversand')) {
        function doppelversand()
        {
        }
        $mail->Send(); // Versenden an Empfänger


    }
   
// =================MAIL-RESPONDER============================
if (isset($FORM[$form_ID][$form_ID . 'send']) && $FORM[$form_ID][$form_ID . 'send'] == 1 && $responder == 'ok' && !$warning_set && isset($absendermail)) 
{
// SETUP	
$Body = $form_template_html . nl2br($responsemail) . '<hr/>' . nl2br($rmailbodyhtml) . $form_template_html_footer;
$To = $absendermail;
$from = "REX_VALUE[2]";
$FromName = "REX_VALUE[8]";
$rsubject = "REX_VALUE[17]";

// SENDEN

$mail = new rex_mailer();
#$mail->Body = $Body;
#$mail->AltBody =  nl2br($responsemail);
$mail->AddAddress($To);
$mail->FromName = $FromName;
$mail->From = $from;
$mail->Sender   = $from ; //Absenderadresse als Return-Path
$mail->Subject = $rsubject;
$mail->Priority = null;

     if ("REX_MEDIA[id=1 output=1]" != '') {
            $mail->AddAttachment($form_attachment);
        }
        if ($form_deliver_org != 'ja') {
            $mail->Body = $responsemail . $nonhtmlfooter;
        } else {
            if ("REX_VALUE[12]" == 'ja') {
                $mail->IsHTML(true);
                $mail->Body    = $form_template_html . nl2br($responsemail) . '<hr/>' . nl2br($rmailbodyhtml) . $form_template_html_footer;
                $mail->AltBody = $responsemail.$rmailbody . $nonhtmlfooter;
            } else {
                $mail->Body = $responsemail . "\n-----------------------------------------------\n" . $rmailbody . $nonhtmlfooter;
            }
        }

 if (!function_exists('doppelversand2')) {
        function doppelversand2()
        {
        }
        $mail->Send(); // Versenden an Empfänger
    }

    }

// =================MAIL-RESPONDER-ENDE=========================
    unset($_SESSION["formcheck"]); //
echo '<div class="formthanks" id="doformREX_SLICE_ID">REX_VALUE[id=6 output=html]</div>';
 $noform = 1;
} else {
    $noform = 0;
}
if ($warning_set) {
    echo '<div class="kblock forminfo">';
    echo ($form_error . $dfreload);
    echo '</div>';
    print $out;
} else {
    if ($noform != 1) {
        print $out;
    }
}
?>




