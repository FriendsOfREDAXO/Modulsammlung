<?php
use FriendsOfRedaxo\MarkItUp\MarkItUp;
  if ('REX_VALUE[id=1 isset=1]') {
    echo MarkItUp::parseOutput ('textile', 'REX_VALUE[id=1 output="html"]');
  }
