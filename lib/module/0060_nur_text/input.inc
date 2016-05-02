<?php

if(!rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "MarkItUp" Addon!');
} else {
  if (!rex_markitup::profileExists('simple')) {
  rex_markitup::insertProfile('simple', 'Angelegt durch das Addon Modulsammlung', 'textile', 'bold,italic,underline,deleted,quote,sub,sup,code,unorderedlist,link[internal|external|mailto]');
  }
  if (!rex_addon::get('textile')->isAvailable()) {
      echo rex_view::error('Dieses Modul benötigt das "textile" Addon!');
  }
}

?>
<div id="nurtext" class="modul-content">
  <div>
    <div class="form-horizontal">
    <h3>Nur Text</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label">Text</label>
        <div class="col-sm-9">
          <textarea id="markitup_textile_1" class="form-control markitup markitupEditor-simple" name="REX_INPUT_VALUE[1]">REX_VALUE[1]</textarea>
        </div>
    </div>

  <div  id="anleitung" >
  <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</h3></div>
  <div id="collapse-text" class="panel-collapse collapse">

  <div class="form-group">
    <label class="col-sm-3 control-label">Nur Text</label>
      <div class="col-sm-9">
        <p>Diese Modul kann dort eingesetzt werden wo nur die Darstellung von Text gewünscht ist. Dies könnten z.B. unterschiedliche Bereiche (Footer, Sidebar) sein oder dafür benutzt werden wenn der Artikel in einem anderen Artikel eingebunden wird. Genaue Auskunft über die Verwendung gibt Ihnen gerne Ihr Websentwickler.</p>
      </div>
    </div>

  </div>
</div>


<style>
#nurtext {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#nurtext h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#nurtext .modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}

#nurtext .select-style {
    border: 1px solid #cccccc;
    width: 100%;
    overflow: hidden;
    background: #fff url("data:image/png;base64,R0lGODlhDwAUAIABAAAAAP///yH5BAEAAAEALAAAAAAPABQAAAIXjI+py+0Po5wH2HsXzmw//lHiSJZmUAAAOw==") no-repeat 98% 50%;
    margin-bottom: 6px;
}
#nurtext .select-style select {
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
#nurtext .select-style select:focus {
    outline: none;
}
#nurtext .select-style select:hover {
    cursor: pointer;
}

#nurtext input.form-control,
#nurtext select.form-control,
#nurtext textarea.form-control {
  background: #fff !important;
}

#nurtext .redactor-editor,
#nurtext .markitup {
  min-height: 200px;
}

#nurtext .redactor-box {
  border: 1px solid #ccc;
}

#nurtext #anleitung .control-label {
  margin-top: -6px;
}

#nurtext #anleitung {
  margin-top: 30px;
}

#nurtext #anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: right;
  margin-bottom: 20px;
  border: none;
}
#nurtext #anleitung .panel-heading span {
  margin-right: 5px;
}

#nurtext #anleitung .panel-heading:hover  {
  color: #000;
}
</style>
