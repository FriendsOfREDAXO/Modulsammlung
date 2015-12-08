<?php
/**
 *
 *
 * Modul:
 *
 * Abstand oder Trennlinie mit/ohne Grafik
 *
 *
 *
 * Empfohlen:       Grafik in den Mediepool laden: 'trenner.png' 30px x 30px
 * Entwickler:      Oliver Kreischer / concedra GmbH
 *
 *
 **/
?>


<div class="modul-content">
  <div id="bereich1" class="">
    <div class="form-horizontal">
      <h3>Abstand oder Trennlinie mit/ohne Grafik</h3>
        <div class="form-group">
          <label class="col-sm-3 control-label">Abstand in PX</label>
          <div class="col-sm-9">
            <input class="form-control" name="REX_INPUT_VALUE[1]" value="REX_VALUE[1]" type="text" />
          </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Linie anzeigen</label>
          <div class="col-sm-9">
            <div class="select-style">
              <select name="REX_INPUT_VALUE[2]">
                <option value="nein"<?php if ('REX_VALUE[2]' == 'nein') echo ' selected'; ?>>nein</option>
                <option value="ja"<?php if ('REX_VALUE[2]' == 'ja') echo ' selected'; ?>>ja</option>
              </select>
            </div>
          </div>
        </div>
        <div class="form-group">
          <label class="col-sm-3 control-label">Grafik anzeigen</label>
          <div class="col-sm-9">
            <div class="select-style">
              <select name="REX_INPUT_VALUE[3]">
                <option value="nein"<?php if ('REX_VALUE[3]' == 'nein') echo ' selected'; ?>>nein</option>
                <option value="ja"<?php if ('REX_VALUE[3]' == 'ja') echo ' selected'; ?>>ja</option>
              </select>
            </div>
          </div>
        </div>


 <div  id="anleitung" >
 <div class="control-label panel-heading collapsed" data-toggle="collapse" data-target="#collapse-text"><span class="caret"></span>Erklärung</h3></div>
  <div id="collapse-text" class="panel-collapse collapse">

    <div class="form-group">
      <label class="col-sm-3 control-label">Abstand in PX</label>
        <div class="col-sm-9">
          <p>Sofern das Feld "Abstand in PX" leer gelassen wird wird ein default Abstand von 30px benutzt.</p>
        </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label">Linie anzeigen</label>
        <div class="col-sm-9">
          <p>Eine Trennlinie wird angezeigt.</p>
        </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label">Grafik anzeigen</label>
        <div class="col-sm-9">
          <p>Zeigt eine Trennline und eine 30x30px große Grafik aus dem Medienpool (trenner.png) an.</p>
        </div>
    </div>

  </div>
  </div>

  </div>
</div>


<style>
.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

.modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}

.select-style {
    border: 1px solid #cccccc;
    width: 100%;
    overflow: hidden;
    background: #fff url("data:image/png;base64,R0lGODlhDwAUAIABAAAAAP///yH5BAEAAAEALAAAAAAPABQAAAIXjI+py+0Po5wH2HsXzmw//lHiSJZmUAAAOw==") no-repeat 98% 50%;
    margin-bottom: 6px;
}
.select-style select {
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
.select-style select:focus {
    outline: none;
}
.select-style select:hover {
    cursor: pointer;
}

input.form-control,
select.form-control,
textarea.form-control {
  background: #fff !important;
}

#anleitung .control-label {
  margin-top: -6px;
}

#anleitung {
  margin-top: 30px;
}

#anleitung .panel-heading {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  text-align: right;
  margin-bottom: 20px;
  border: none;
}
#anleitung .panel-heading span {
  margin-right: 5px;
}

#anleitung .panel-heading:hover  {
  color: #000;
}
</style>
