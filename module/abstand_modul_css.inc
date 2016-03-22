$trennline: #ccc;

.trenner {
  clear: both;
  display: block;
  text-align: center;
  overflow: hidden;
  white-space: nowrap;

  span {
    position: relative;
    display: inline-block;
    &:before,
    &:after {
      content: "";
      position: absolute;
      top: 50%;
      width: 9999em;
      height: 1px;
      background: #fff;
    }
    &:before {
      right: 100%;
      margin-right: -15px;
    }
    &:after {
      left: 100%;
      margin-left: -15px;
    }
  }

  &.trennerlinie {
    span {
      &:before,
      &:after {
        background: $trennline !important;
      }
    }
    &:before,
    &:after {
      content: "";
      position: absolute;
      top: 55%;
      width: 9999em;
      height: 1px;
      background: $trennline;
    }
  }

  &.trennerliniemitgrafik {
    position: relative;
    min-height: 30px;
    span {
	   height: 30px;
      &:before {
    	 position: absolute;
	     top: 45%;
         margin-right: 50%;
         background: $trennline !important;
      }
      &:after {
	    position: absolute;
        top: 45%;
        margin-left: 15px;
        background: $trennline !important;
      }
    }
  }
    
}
