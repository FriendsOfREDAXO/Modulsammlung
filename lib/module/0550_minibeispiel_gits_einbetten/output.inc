<?php

if(!rex::isBackend()) {

    if ('REX_VALUE[1]' != '') {
        echo '
        <div class="container">
          <div class="row">
            <div class="col-xs-12">
                <script src="REX_VALUE[1].js"></script>
            </div>
          </div>
        </div>
        
        <style>
          .gist-meta {
            display: none;
          }
        </style>';
    }

} else {

    if ('REX_VALUE[1]' != '') {
        $gisturl = 'REX_VALUE[1]';
    } else {
        $gisturl = '<b>Es wurde keine URL angegeben. Im Frontend wird nichts ausgegeben!</b>';
    }

    echo '
  <div id="gist" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2>Gist</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Gits URL</label>
         <div class="col-sm-9">'. $gisturl .'</div>
       </div>
    </div>
  </div>

<style>
#gist .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#gist .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#gist  h2 {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>'.PHP_EOL;
}

