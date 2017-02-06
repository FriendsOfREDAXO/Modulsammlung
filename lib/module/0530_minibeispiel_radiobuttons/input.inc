<div id="radioexample" class="modul-content">
  <div class="form-horizontal">
    <h3>Radios Buttons Beispiel</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label" for="headline-level">Radios</label>
      <div class="col-sm-9">
        <div class="btn-group btn-group-vertical" data-toggle="buttons">
          <?php
            $options = array('Wert 1', 'Wert 2', 'Wert A', 'Wert B');
            $current = "REX_VALUE[1]";
            foreach ( $options as $option) {
                if ($option == $current) {
                echo '
                  <label class="btn active">
                    <input type="radio" name="REX_INPUT_VALUE[1]" value="'. $option .'" checked /><i class="fa fa-circle-o"></i><i class="fa fa-check-circle-o"></i> <span>  '. $option .'</span>
                  </label>';

                } else {
                echo '
                  <label class="btn">
                  <input type="radio" name="REX_INPUT_VALUE[1]" value="'. $option .'"/><i class="fa fa-circle-o"></i><i class="fa fa-check-circle-o"></i><span> '. $option .'</span>
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
#radioexample.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#radioexample.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#radioexample.modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}


#radioexample label.btn span {
  font-size: 1.2em ;
}

#radioexample label input[type="radio"] ~ i.fa.fa-circle-o{
  color: #999;    display: inline;
  font-size: 1.2em ;
}
#radioexample label input[type="radio"] ~ i.fa.fa-check-circle-o{
  display: none;
  font-size: 1.2em ;
}
#radioexample label input[type="radio"]:checked ~ i.fa.fa-circle-o{
  display: none;
}
#radioexample label input[type="radio"]:checked ~ i.fa.fa-check-circle-o{
  color: #36404F;
  display: inline;
}
#radioexample label:hover input[type="radio"] ~ i.fa {
  color: #36404F;
}
#radioexample label input[type="checkbox"] ~ i.fa.fa-square-o{
  color: #999;
  display: inline;
}
#radioexample label input[type="checkbox"] ~ i.fa.fa-check-square-o{
  display: none;
}
#radioexample label input[type="checkbox"]:checked ~ i.fa.fa-square-o{
  display: none;
}
#radioexample label input[type="checkbox"]:checked ~ i.fa.fa-check-square-o{
  color: #36404F;    display: inline;
}
#radioexample label:hover input[type="checkbox"] ~ i.fa {
  color: #36404F;
}

#radioexample div[data-toggle="buttons"] {
  width: 100%;
}

#radioexample div[data-toggle="buttons"] label.active{
    color: #36404F;
}

#radioexample div[data-toggle="buttons"] label {
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

#radioexample div[data-toggle="buttons"] label:hover {
  color: #36404F;
}

#radioexample * {
  outline: none !important;
}

#radioexample div[data-toggle="buttons"] label:active, div[data-toggle="buttons"] label.active {
  -webkit-box-shadow: none;
  box-shadow: none;
  -webkit-appearance: none;
  -moz-appearance: none;
}
</style>
