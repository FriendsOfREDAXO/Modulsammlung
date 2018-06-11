<b>Single Select:</b><br/>
  REX_VALUE[1]
<br/>
<b>Multiselect:</b></br/>
<?php
  $value_multiselect = rex_var::toArray('REX_VALUE[2]');

  foreach($value_multiselect as $result) {
      echo $result, '<br>';
}
