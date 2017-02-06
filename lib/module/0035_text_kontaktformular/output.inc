<?php
if(!rex_addon::get('markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
}

$textnebenformular    = '';
$email                = 'REX_VALUE[2]';
$textdanke            = '';
$emailabsender        = 'REX_VALUE[4]';

if ($emailabsender == '') {
  $emailabsender = rex::getErrorEmail();
}

if ('REX_VALUE[id=1 isset=1]') {
    $textnebenformular = markitup::parseOutput ('textile', 'REX_VALUE[id=1 output="html"]');
}

if ('REX_VALUE[id=3 isset=1]') {
    $textdanke = markitup::parseOutput ('textile', 'REX_VALUE[id=3 output="html"]');
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
        '.$textnebenformular.'
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
         <div class="col-sm-9">'.$textnebenformular.'</div>
       </div>
       <div class="form-group">
         <label class="col-sm-3 control-label">Text (Danke)</label>
         <div class="col-sm-9">'.$textdanke.'</div>
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
