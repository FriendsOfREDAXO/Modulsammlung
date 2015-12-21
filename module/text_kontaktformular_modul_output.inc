<?php
$editor                 = 0;
if(!rex_addon::get('rex_redactor')->isAvailable() AND !rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "Redactor" oder das "MarkItUp" Addon!');
}
if(rex_addon::get('rex_redactor')->isAvailable()) {
  $editor = 'redactor';
  $ausgabe_art ='1';
 }
if(rex_addon::get('rex_markitup')->isAvailable()) {
  $editor = 'markitup';
  $ausgabe_art ='2';
}

$ausgabeart           = '0';
$textnebenformular    = 'REX_VALUE[1]';
$textnebenformular1   = '';
$email                = 'REX_VALUE[2]';
$textdanke            = 'REX_VALUE[3]';
$emailabsender        = 'REX_VALUE[4]';

if ($emailabsender == '') {
  $emailabsender = rex::getErrorEmail();
}

if ($textnebenformular !='') {
  if ($editor == 'markitup' AND rex_addon::get('textile')->isAvailable()) {
    $textnebenformular1 = str_replace('<br />', '', $textnebenformular);
    $textnebenformular1 = rex_textile::parse($textnebenformular);
  }
}


$formular = '';

$yform = new rex_yform();

$form_data = '

objparams|form_id|kontaktformular
objparams|form_skin|bootstrap
objparams|form_showformafterupdate|0
objparams|real_field_names|true

text|name|Name|#placeholder:Name
validate|empty|name|Bitte geben Sie Ihren Namen an.|
text|email|E-Mail|#placeholder:E-Mail
validate|empty|email|Bitte geben Sie Ihre E-Mail Adresse an.|
validate|email|email|Bitte geben Sie eine richtige E-Mail Adresse an.|
textarea|nachricht|Nachricht|#placeholder:Nachricht
validate|empty|name|Bitte geben Sie eine Nachricht ein.|

action|email|'.$emailabsender.'|'.$email.'|Nachricht von der Webseite (Kontaktformular)|<b>Name:</b> ###name###<br/><b>E-Mail:</b> ###email###<br/><br/><b>Nachricht:</b><br/>###nachricht###

submit|label|Senden|||

action|showtext|'.$textdanke.'|||1
';

$yform->setFormData($form_data);

$url = rex_getUrl($this->getArticleId());
$yform->setObjectparams("form_action", $url);

if(!rex::isBackend()) {

echo '
  <div class="container">
  <div class="row">
    <div class="col-xs-12 col-sm-6">
        '.$textnebenformular1.'
    </div>
    <div class="col-xs-12 col-sm-6">
        '.$yform->getForm().'
    </div>
  </div>
  </div>
';
} else {
 echo '
  <div id="textformular" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2 class="ueberschrift" >Text / Kontaktformular</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">E-Mail Adresse</label>
         <div class="col-sm-9">'.$email.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">E-Mail Adresse Absender</label>
         <div class="col-sm-9">'.$emailabsender.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Text neben Formular</label>
         <div class="col-sm-9">'.$textnebenformular1.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Text (Danke)</label>
         <div class="col-sm-9">'.$textdanke1.'</div>
       </div>
    </div>
  </div>

<style>
#textformular .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#textformular .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#textformular  h2.ueberschrift {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>'.PHP_EOL;
}
