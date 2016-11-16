<?php

if(!rex_addon::get('markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
} else {
  if (!markitup::profileExists('simple')) {
    markitup::insertProfile('simple', 'Angelegt durch das Addon Modulsammlung', 'textile', 300, 800, 'relative', 'bold,italic,underline,deleted,quote,sub,sup,code,unorderedlist,grouplink[internal|external|mailto]');
  }
}

?>
<div id="textformular" class="modul-content">
  <div>
    <div class="form-horizontal">
    <h3 class="ueberschrift" >Text / Kontaktformular</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label">Empfänger E-Mail</label>
      <div class="col-sm-9">
        <input class="form-control" name="REX_INPUT_VALUE[2]" value="REX_VALUE[2]" type="text" />
        </div>
      </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Absender E-Mail</label>
      <div class="col-sm-9">
        <input class="form-control" name="REX_INPUT_VALUE[4]" value="REX_VALUE[4]" type="text" />
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Text neben Formular</label>
      <div class="col-sm-9">
          <textarea id="markitup_textile_1" class="form-control markitup markitupEditor-simple" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
      </div>
    </div>
    <div class="form-group">
      <label class="col-sm-3 control-label">Text (Danke)</label>
        <div class="col-sm-9">
          <textarea id="markitup_textile_2" class="form-control markitup markitupEditor-simple" name="REX_INPUT_VALUE[3]">REX_VALUE[3]</textarea>
        </div>
    </div>

  <div  id="anleitung" >
  <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</h3></div>
  <div id="collapse-text" class="panel-collapse collapse">
  <div class="form-group">
    <label class="col-sm-3 control-label">Empfänger E-Mail</label>
      <div class="col-sm-9">
        <p>An diese E-Mail Adresse wird das Formular bzw. die Daten gesendet.</p>
      </div>
    <label class="col-sm-3 control-label">Absender E-Mail</label>
      <div class="col-sm-9">
        <p>Diese E-Mail Adresse wird als Absender Adresse eingetragen.</p>
      </div>
    </div>
  <div class="form-group">
    <label class="col-sm-3 control-label">Text neben Formular</label>
      <div class="col-sm-9">
        <p>Dieser Text wird neben (über) dem Formular dargestellt.</p>
      </div>
    </div>
  <div class="form-group">
    <label class="col-sm-3 control-label">Text (Danke)</label>
      <div class="col-sm-9">
        <p>Sofern das Formular erfolgreich ausgefüllt und abgeschickt wurde erscheint dieser Text.</p>
      </div>
    </div>
  </div>
</div>


<style>
#textformular {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#textformular h3.ueberschrift {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#textformular .control-label {
  font-weight: normal;
  font-size: 12px !important;
}


#textformular input.form-control,
#textformular select.form-control,
#textformular textarea.form-control {
  background: #fff !important;
}

#textformular textarea {
  min-height: 200px;
}

#textformular .redactor-box {
  border: 1px solid #ccc;
}

#textformular #anleitung .control-label {
  margin-top: -6px;
}

#textformular #anleitung {
  margin-top: 30px;
}

#textformular #anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: left;
  margin-bottom: 20px;
  border: none;
}
#textformular #anleitung .panel-heading span {
  margin-right: 5px;
}

#textformular #anleitung .panel-heading:hover  {
  color: #000;
}
</style>
