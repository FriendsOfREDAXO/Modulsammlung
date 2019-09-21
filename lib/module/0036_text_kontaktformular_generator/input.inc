<?php
/**
 *=============================================
 * REDAXO-Modul: Formulargenerator
 * Bereich: Eingabe 
 * Version: 6.2.1;
 * ab Redaxo Version: 5
 * Hinweise:
 * Formulargenerator für PHPMAILER
 * Required Addons: phpmailer, yform
 * Ursprung: Formular-Generator Redaxo 3.2 Demo, do form! bis Version 6
 * Typ: Portierung und Weiterentwicklung für REDAXO 5.x 
 *=============================================
*/
// EINGABE EINSTELLUNGEN
// zur Vereinfachung der Eingabemaske
// Erweiterte Funktionen in der Moduleingabe freischalten 
// Es sind evtl. Anpassungen im ausgabe-Code erforderlich

$uploadon=true;  // UPLOADS AKTIVIEREN true oder false, beachte: Ausgabe $form_upload_folder
$bccon=true;  // BCC-Feld AKTIVIEREN true oder false
$weditor='cke5'; // Welches WYSIWYG-addon soll verwendet werden? z.B.: redactor2 ckeditor oder tinymce 
$editstyle='cke5-editor'; // Lege die CSS-Klasse für den WYSIWYG-Editor fest (z.B. ckeditor oder tinyMCEEditor) 

// Definition des Standard-Formulars 
$defaultdata='
radio|Geschlecht|0|Weiblich;Männlich;Divers|w;m;d|
text|Vorname|1|||checkfield
text|Nachname|1|||name
text|Firma |
text|Straße|
text|PLZ|1|||plz
text|Ort|1|||
text|Telefon||||tel
text|Telefax||||tel
email|E-Mail|1|||sender
textarea|Ihre Nachricht: |1|
checkbox|Ich habe die <a target="_blank" href="/datenschutz/">Datenschutzerklärung</a> gelesen|1|
info|Geben Sie bitte nochmal Ihren Vornamen ein
text|Nachname|1|||check
';
$sessionson = false;  
 
 
/**
 * Convert a shorthand byte value from a PHP configuration directive to an integer value
 * @param    string   $value
 * @return   int
 */
if (!function_exists('convertBytes')) {
function convertBytes( $value ) {
    if ( is_numeric( $value ) ) {
        return $value;
    } else {
      $value = trim ($value);
      $value_length = strlen( $value );
      $qty = substr( $value, 0, $value_length - 1 );
      $unit = strtolower( substr( $value, $value_length - 1 ) );
      switch ( $unit ) {
          case 'g':
              $qty *= 1024;
          case 'm':
              $qty *= 1024;
          case 'k':
              $qty *= 1024;
      }
      return $qty;
    }
}
}
?>
<script language="JavaScript" type="text/javascript"> 
<!-- 
function doIt(theValue) 
{ 
    var divs=document.getElementsByTagName("DIV"); 
    for (var i=0;i<divs.length;i++) 
    { 
        if (divs[i].className=="myDivs") 
        { 
        divs[i].style.display=(( theValue=="every" || divs[i].id==theValue)?"block":"none"); 
        }; 
    } 
} 
//--> 
</script>






<div class="form-horizontal text-left">


<div class="form-group">
	<label class="col-sm-12 control-label text-left"></label>
	    <div class="col-sm-12">
Formularfelder
	         <textarea name="REX_INPUT_VALUE[3]" rows="15" class="form-control codemirror"><?php if ("REX_VALUE[3]" == ''){echo $defaultdata;} else {echo "REX_VALUE[3]";}?></textarea><a href="#anleitung" id="anzeige" onclick="javascript:document.getElementById('anleitung').style.display = 'block'" > <i class="fa fa-question-circle"></i> Beispiel-einblenden </a>
	    </div>
</div>	
	

<div class="form-group">
	<label class="col-sm-3 control-label">E-Mail geht an:</label>
	    <div class="col-sm-9">
	         <input type="email" name="REX_INPUT_VALUE[1]" value="REX_VALUE[1]" placeholder="name@domian.tld" class="form-control"  />
	         <span class="small">Platzhalter: %Mail%</span>
	    </div>
</div>	

<?php 
// Wurde BB in der Config aktiviert? 
if ($bccon==true) { ?>  
<div class="form-group">
	<label class="col-sm-3 control-label">BCC:</label>
	    <div class="col-sm-9">
	         <input type="text" class="form-control" placeholder="bcc@domian.tld" name="REX_INPUT_VALUE[11]" value="REX_VALUE[11]"  />
	         <span class="small">Sie können einen BCC-Empfänger eingeben</span>
	    </div>
</div>	
<?php } ?>   
 

<div class="form-group">
	<label class="col-sm-3 control-label">Betreff</label>
	    <div class="col-sm-9">
	         <input type="text" class="form-control" name="REX_INPUT_VALUE[4]" placeholder="Anfrage zu…" value="REX_VALUE[4]"  />
	    </div>
</div>	

<div class="form-group">
	<label class="col-sm-3 control-label">Bezeichnung des Sendebuttons</label>
	    <div class="col-sm-9">
	         <input type="text" class="form-control" name="REX_INPUT_VALUE[7]" value="REX_VALUE[7]"  />
	    </div>
</div>	


<div class="form-group">
	<label class="col-sm-3 control-label">HTML-E-Mail:</label>
	    <div class="col-sm-9">
	         <select  class="form-control selectpicker" name="REX_INPUT_VALUE[12]">
             <option value='ja' <?php if ("REX_VALUE[12]" == 'ja') echo 'selected'; ?>>ja</option>
             <option value='nein' <?php if ("REX_VALUE[12]" == 'nein') echo 'selected'; ?>>nein</option >
             </select>
             <br><span class="small">Soll die E-Mail im HTML-Format verschickt werden?</span>
	    </div>
</div>	

<div class="form-group">
	<label class="col-sm-3 control-label">Bestätigungs-Mail senden?:</label>
	    <div class="col-sm-9">
	         <select class="form-control selectpicker" name="REX_INPUT_VALUE[10]" id="mySelect" onChange="doIt(this.value)">
             <option value='Nein' <?php if ("REX_VALUE[10]" == 'nein') echo 'selected'; ?>>Nein</option>
             <option value='ok' <?php if ("REX_VALUE[10]" == 'ok') echo 'selected'; ?>>Ja</option>
             </select>
	         <br><span class="small">Es muss ein Feld mit der Validierung "sender" definiert sein</span>
	    </div>
</div>	

<?php 
// Wurden Uploads erlaubt
if ($uploadon==true) { ?>
<div class="form-group">
	<label class="col-sm-3 control-label">Uploads als Anhang versenden?</label>
	    <div class="col-sm-9">
	         <select class="form-control selectpicker" name="REX_INPUT_VALUE[15]">
             <option value='Nein' <?php if ("REX_VALUE[15]" == 'nein') echo 'selected'; ?>>Nein</option>
             <option value='Ja' <?php if ("REX_VALUE[15]" == 'Ja') echo 'selected'; ?>>Ja</option>
             </select>
	         <br><span class="small">Maximale Größe: <?php echo 'Uploadgr&#246;&#223;e, max: ' . convertBytes( ini_get( 'upload_max_filesize' ) ) / 1048576 . 'MB';?></span>
	    </div>
</div>	

<?php } ?>  


<?php if ($sessionson==true) { ?>
<div class="form-group">
	<label class="col-sm-3 control-label">Bezeichner für Sessionvariable:</label>
	    <div class="col-sm-9">
	        <input type="text" name="REX_INPUT_VALUE[16]" value="REX_VALUE[16]" class="form-control" />
	        <br>Beispiel: Einsatz per <code>svar|Warenkorb</code>
	    </div>
</div>	
<?php } ?>



<div id="ok" <?php if ("REX_VALUE[10]" == 'ok'){ echo 'style="display:block;"'; } else echo 'style="display:none;"'; ?> class="myDivs">

<div class="form-group">
	<label class="col-sm-3 control-label">Betreff für die Bestätigungs-E-Mail</label>
	    <div class="col-sm-9">
	         <input type="text" name="REX_INPUT_VALUE[17]" value="REX_VALUE[17]" class="form-control" />
	    </div>
</div>	

<div class="form-group">
	<label class="col-sm-3 control-label">Absenderadresse für die Bestätigungs-E-Mail</label>
	    <div class="col-sm-9">
	          <input type="email" name="REX_INPUT_VALUE[2]" value="REX_VALUE[2]" class="form-control" />
	          <br><span class="small">Platzhalter: %Absender%</span>
	    </div>
</div>	

<div class="form-group">
	<label class="col-sm-3 control-label">Absendername für die Bestätigungs-E-Mail</label>
	    <div class="col-sm-9">
	          <input type="text" name="REX_INPUT_VALUE[8]" value="REX_VALUE[8]" class="form-control" />
	    </div>
</div>	


<div class="form-group">
	<label class="col-sm-3 control-label">Original anhängen?</label>
	    <div class="col-sm-9">
	          <select  class="form-control selectpicker" name="REX_INPUT_VALUE[13]">
              <option value='nein' <?php if ("REX_VALUE[13]" == 'nein') echo 'selected'; ?>>nein</option >
              <option value='ja' <?php if ("REX_VALUE[13]" == 'ja') echo 'selected'; ?>>ja</option>
      </select>
	    </div>
</div>	

<div class="form-group">
	<label class="col-sm-3 control-label">Datei anhängen</label>
	    <div class="col-sm-9">
	          REX_MEDIA[id=1 widget=1]
	    </div>
</div>	

<div class="form-group">
	<label class="col-sm-3 control-label">Bestätigungstext</label>
	    <div class="col-sm-9">
	          <textarea name="REX_INPUT_VALUE[5]" class="form-control" style="width:100%;height:80px;">REX_VALUE[5]</textarea>
	          <span class="formgen_sample1"><strong>Platzhalter für Bestätigungstext:</strong> <br />
    %Betreff%, %Datum% , %Zeit%, %Absender%, %Mail%, %Vorname%, %Nachname% </span>, <br />
    %Usermail% (wird durch Adresse mit Validierung sender gesetzt)<br/>
	    </div>
</div>	

	
</div>	


<div class="form-group">
	<label class="col-sm-3 control-label">Bestätigung auf der Website </label>
	    <div class="col-sm-9">
	          <textarea id="redactor_REX_SLICE_ID"name="REX_INPUT_VALUE[6]" class="<?php echo $editstyle;?> form-control" style="width:555px; height:250px;">REX_VALUE[6]</textarea>
	    </div>
</div>	

</div>	
<div class="form-horizontal">
<div id="anleitung" style="<?php echo (!isset ($anleitung) || !$anleitung) ? 'display: none' : 'display: block'; ?>"> 
  <div class="formgenheadline">Beispiel-Formular:</div>
  <div class="col-md-12 doform">
    <textarea name="demo" cols="80" rows="11" class="form-control">
fieldstart|Kontaktdaten
text|Name|1|||checkfield    
text|Vorname|1|||name
text|Firma
text|Straße
text|PLZ|1|||plz
text|Ort|1
text|Telefon||||tel
text|Telefax||||tel
fieldend|
fieldstart|Weitere Angaben
divstart|cssklasse
radio|Geschlecht|0|Mann;Frau|m;w|
password|Ihr Passwort|1|||alpha
email|E-Mail|1|||sender
url|Website||||url
divend|
select|Auswahl|1||Birne;Apfel;Kirsche
checkbox|AGB gelesen?
fieldend|
info|Geben Sie bitte nochmal Ihren Namen ein
text|Sicherheitscode|1|||check
textarea|Ihre Nachricht:|1|
upload|Upload JPG|0||jpg;jpeg;gif||0.5m
checkbox|Ich habe die <a href="/datenschutz/">Datenschutzerklärung</a> gelesen|1|        
</textarea>
    <br/>
    <br/>
  </div>
  <h3>Kurzbeschreibung:</h3>
  do form! basiert auf den in Redaxo 3.2 mitgelieferten Formular-Generator.<br />
   Beim ersten Aufruf erstellt das Modul eine Konfiguration für ein Standard-Kontaktformular. <br/>
     Im Beispiel-Formular sehen Sie Möglichkeiten zur Konfiguration. <br/>
<strong>Empfehlung:</strong><br />
     Wir empfehlen im PHP-Mailer die Einstellung SMTP-AUTH zu verwenden. 
  <br />
  <div class="col-md-12 doform"><strong>Validierung</strong> von Textfeldern </span>
    
      <ul>
        <li>alpha (nur engl.Buchstaben) </li>
        <li>url (URL)</li>
        <li>date</li>
        <li>time</li>
        <li>IBAN</li>
        <li>BIC</li>
        <li>digit (nur Zahlen)</li>
        <li>plz (5 Zahlen)</li>
        <li>plz4 (4 Zahlen)</li>
        <li>tel</li>
        <li>name prüft Namen und z.B. übliche Firmenbezeichnungen</li>
        <li>mail (pr&uuml;ft eingegebene E-Mail-Adressen) </li>
        <li>sender (diese Adresse wird als Absendermail eingesetzt und gepr&uuml;ft)</li>
        <li>check - Prüfen der Spamschutzeingabe (captchapic oder checkfield) <br/>
          entspricht sonst der Validierung: name</li>
        <li>checkfield (legt ein Vergleichsfeld fest das als Spamschutzcode gilt)</li>
      </ul>
      <p>&nbsp;</p>
    <div style="clear:both"></div>
  </div>
  <br />
<br />
</div>


</div>
