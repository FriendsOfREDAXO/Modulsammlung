<div id="checkboxexample" class="modul-content">
  <div class="form-horizontal">
    <h3>Checkboxen Beispiel</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label" for="headline-level">Checkboxen</label>
      <div class="col-sm-9">
        <div class="btn-group btn-group-vertical" data-toggle="buttons">
          <?php
            $options = array('Wert 1', 'Wert 2', 'Wert A', 'Wert B');
            $current[] = rex_var::toArray('REX_VALUE[1]');
            foreach ( $options as $option) {
              if ($option == in_array($option, $current)) {
                echo '
                  <label class="btn active">
                    <input type="checkbox" name="REX_INPUT_VALUE[1][]" value="'. $option .'" checked /><i class="fa fa-square-o"></i><i class="fa fa-check-square-o"></i> <span>  '. $option .'</span>
                  </label>';
                } else {
                echo '
                  <label class="btn">
                  <input type="checkbox" name="REX_INPUT_VALUE[1][]" value="'. $option .'"/><i class="fa fa-square-o"></i><i class="fa fa-check-square-o"></i><span> '. $option .'</span>
                  </label>';
              }
            }
          ?>
        </div>
      </div>
    </div>
  </div>
</div>


<style>
#checkboxexample.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#checkboxexample.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#checkboxexample.modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}


#checkboxexample label.btn span {
  font-size: 1.2em ;
}
#checkboxexample label input[type="checkbox"] ~ i {
  display: inline-block;
}


#checkboxexample label input[type="checkbox"] ~ i.fa.fa-square-o{
  color: #999;
  display: inline;
  font-size: 1.2em;
}
#checkboxexample label input[type="checkbox"] ~ i.fa.fa-check-square-o{
  display: none;
  font-size: 1.2em;
}
#checkboxexample label input[type="checkbox"]:checked ~ i.fa.fa-square-o{
  display: none;
}
#checkboxexample label input[type="checkbox"]:checked ~ i.fa.fa-check-square-o {
  color: #36404F;
  display: inline;
}
#checkboxexample label:hover input[type="checkbox"] ~ i.fa {
  color: #36404F;
}
#checkboxexample label input[type="checkbox"] ~ i.fa.fa-square-o{
  color: #999;
  display: inline;
  margin-right: 6px;
}
#checkboxexample label input[type="checkbox"] ~ i.fa.fa-check-square-o{
  display: none;
}
#checkboxexample label input[type="checkbox"]:checked ~ i.fa.fa-square-o{
  display: none;
}
#checkboxexample label input[type="checkbox"]:checked ~ i.fa.fa-check-square-o{
  margin-right: 4px;
  color: #36404F;
  display: inline;
}
#checkboxexample label:hover input[type="checkbox"] ~ i.fa {
    color: #36404F;
}

#checkboxexample div[data-toggle="buttons"] {
  width: 100%;
}

#checkboxexample div[data-toggle="buttons"] label.active{
    color: #36404F;
}

#checkboxexample div[data-toggle="buttons"] label {
  display: inline-block;
  padding: 6px 12px;
  font-size: 12px;
  font-weight: normal;
  line-height: 1.6em;
  text-align: left;
  vertical-align: top;
  white-space: normal;
  cursor: pointer;
  background-color: none;
  border-bottom: 1px solid #e0e0e0;
  color: #999;
  -webkit-user-select: none;
  -moz-user-select: none;
  -ms-user-select: none;
  -o-user-select: none;
  user-select: none;
}

#checkboxexample div[data-toggle="buttons"] label:hover {
  color: #36404F;
}

#checkboxexample * {
    outline: none !important;
}

#checkboxexample div[data-toggle="buttons"] label:active, div[data-toggle="buttons"] label.active {
  -webkit-box-shadow: none;
  box-shadow: none;
  -webkit-appearance: none;
  -moz-appearance: none;
}
</style>
