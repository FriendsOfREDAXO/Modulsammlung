<?php

if(!rex_addon::get('markitup')->isAvailable() OR !rex_addon::get("yform")->isAvailable() OR !rex_plugin::get("yform", "tools")->isAvailable()) {
  echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp", "yForm" und das Plugin "yForm/tools" Addon!');
}
?>
<div id="bootstrap_modal" class="modul-content">
  <div>
    <div class="form-horizontal">
      <h3>Titel</h3>
      <div class="form-group">
        <label class="col-sm-3 control-label">Titel:</label>
        <div class="col-sm-9">
          <input class="form-control" name="REX_INPUT_VALUE[2]" value="REX_VALUE[2]" type="text" />
        </div>
      </div>
    </div>

    <div class="form-horizontal">
      <h3>Inhalt</h3>
      <div class="form-group">
        <label class="col-sm-3 control-label">Text</label>
        <div class="col-sm-9">
          <textarea id="markitup_textile_1" class="form-control markitup markitupEditor-simple" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
        </div>
      </div>

      <div class="form-horizontal">
        <h3>Anzeigezeitraum:</h3>
        <div class="form-group">
          <label class="col-sm-3 control-label">Startzeit</label>
          <div class="col-sm-9">
            <input class="form-control" name="REX_INPUT_VALUE[3]" value="REX_VALUE[3]" type="text" data-yform-tools-datetimepicker = "DD-MM-YYYY HH:ii" data-yform-tools-inputmask = "99-99-9999 99:99" />
          </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Endzeit</label>
          <div class="col-sm-9">
            <input class="form-control" name="REX_INPUT_VALUE[4]" value="REX_VALUE[4]" type="text" data-yform-tools-datetimepicker = "DD-MM-YYYY HH:ii" data-yform-tools-inputmask = "99-99-9999 99:99"/>
          </div>
        </div>

        <div  id="anleitung" >
          <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</h3></div>
          <div id="collapse-text" class="panel-collapse collapse">

            <div class="form-group">
              <label class="col-sm-3 control-label">Nur Text</label>
              <div class="col-sm-9">
                <p>Dieses Modul kan in einem Artikel eingesetzt werden. Mit unterscheidlichen Zeitangaben (keine Überschneidungen!!!) kann das Modul auch mehrfach in einem Artikel eingefügt werden.</p>
              </div>
            </div>

          </div>
        </div>


        <style>
          #bootstrap_modal {
            background: #f5f5f5;
            padding: 10px 30px 30px 15px;
            border: 1px solid #9da6b2;
          }

          #bootstrap_modal h3 {
            font-size: 14px !important;
            padding: 10px;
            background: #DFE3E9;
            width: 100%;
            margin-bottom: 20px;
          }

          #bootstrap_modal .modul-content .control-label {
            font-weight: normal;
            font-size: 12px !important;
          }

          #bootstrap_modal .select-style {
            border: 1px solid #cccccc;
            width: 100%;
            overflow: hidden;
            background: #fff url("data:image/png;base64,R0lGODlhDwAUAIABAAAAAP///yH5BAEAAAEALAAAAAAPABQAAAIXjI+py+0Po5wH2HsXzmw//lHiSJZmUAAAOw==") no-repeat 98% 50%;
            margin-bottom: 6px;
          }
          #bootstrap_modal .select-style select {
            padding: 5px 8px;
            width: 100%;
            border: none;
            box-shadow: none;
            background: transparent;
            background-image: none;
            -webkit-appearance: none;
            -moz-appearance:none;
            -webkit-border-radius: 0px;
          }
          #bootstrap_modal .select-style select:focus {
            outline: none;
          }
          #bootstrap_modal .select-style select:hover {
            cursor: pointer;
          }

          #bootstrap_modal input.form-control,
          #bootstrap_modal select.form-control,
          #bootstrap_modal textarea.form-control {
            background: #fff !important;
          }

          #bootstrap_modal #markitup_textile_1 {
            min-height: 200px;
          }

          #bootstrap_modal .redactor-box {
            border: 1px solid #ccc;
          }

          #bootstrap_modal #anleitung .control-label {
            margin-top: -6px;
          }

          #bootstrap_modal #anleitung {
            margin-top: 30px;
          }

          #bootstrap_modal #anleitung .panel-heading {
            font-size: 14px !important;
            padding: 10px;
            background: #DFE3E9;
            width: 100%;
            text-align: right;
            margin-bottom: 20px;
            border: none;
          }
          #bootstrap_modal #anleitung .panel-heading span {
            margin-right: 5px;
          }

          #bootstrap_modal #anleitung .panel-heading:hover  {
            color: #000;
          }
        </style>
