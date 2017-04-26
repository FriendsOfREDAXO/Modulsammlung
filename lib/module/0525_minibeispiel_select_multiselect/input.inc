<div id="selectexample" class="modul-content">
  <div class="form-horizontal">
    <h3>Select Beispiel</h3>
    <div class="form-group">
      <label class="col-sm-3 control-label" for="headline-level">Single Select</label>
      <div class="col-sm-9">
        <?php
         $options = array(
          'option eins'=>'Option 1',
          'option zwei'=>'Option 2',
          'option drei'=>'Option 3'
         );
        ?>
        <div class="rex-select-style">
          <select name="REX_INPUT_VALUE[1]" id="select_example" class="form-control">
          <?php foreach ($options as $k=>$v) : ?>
            <option value="<?php echo $k; ?>"<?php if ($k == "REX_VALUE[1]") echo ' selected="selected"' ?>><?php echo $v; ?></option>
          <?php endforeach ?>
          </select>
        </div>
      </div>
    </div>

    <div class="form-group">
      <label class="col-sm-3 control-label" for="headline-level">Multiselect</label>
      <div class="col-sm-9">
        <div class="rex-select-style">
          <?php
            $value_multiselect = rex_var::toArray('REX_VALUE[2]');
            $s = new rex_select();
            $s->setName('REX_INPUT_VALUE[2][]');
            $s->setMultiple();
            $s->addOptions(array(
              'option eins' => 'Option 1',
              'option zwei' => 'Option 2',
              'option drei' => 'Option 3',
              'option vier' => 'Option 4',
              'option fuenf' => 'Option 5',
              'option sechs' => 'Option 6'));
            $s->setSelected($value_multiselect);
            echo $s->get();
          ?>
        </div>
      </div>
    </div>
  </div>
</div>


<style>
#selectexample.modul-content {
  background: #f5f5f5;
  padding: 10px 30px 30px 15px;
  border: 1px solid #9da6b2;
}

#selectexample.modul-content h3 {
  font-size: 14px !important;
  padding: 10px;
  background: #DFE3E9;
  width: 100%;
  margin-bottom: 20px;
}

#selectexample.modul-content .control-label {
  font-weight: normal;
  font-size: 12px !important;
}


</style>
