<?php
  if ('REX_VALUE[id=1 isset=1]') {
      $text = 'REX_VALUE[id=1 output=html]';
      $text = rex_textile::parse($text);
  } else {
    $text = 'Kein Text eingegeben!';
  }
  echo $text;
