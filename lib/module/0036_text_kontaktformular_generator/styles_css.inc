.doform {
	box-sizing: border-box;
	display: block;
	padding: 0;
	text-align: left;
}

.doform div, .doform textarea, .doform input {
	box-sizing: border-box;
}

.doform .formsubmit {
	clear: both;
}

.doform .doformdiv {
	display: block;
	float: left;
	width: 50%;
}

.doform .doformdiv2 {
	display: block;
	float: left;
	padding-left: 25px;
	width: 50%;
}

.doform .formheadline {
	color: #000;
	font-size: 1.5em;
	font-weight: 300;
	margin-bottom: .5em;
}

.doform .formhinweis {
	color: #000;
	font-size: 1em;
	font-weight: 600;
	margin-bottom: .5em;
}

.doform .radioblock {
	margin-bottom: 1.5em;
	margin-top: 1.5em;
}

.doform .radiofield {
	box-sizing: border-box;
	color: #333;
	float: left;
	padding: 10px;
	text-align: center;
	width: 25%;
}

.doform .radiofield input[type=radio] {
	display: none;
}

.doform .radiofield label {
	border: none;
	box-sizing: border-box;
	display: block;
	float: left;
	font-size: 1.5em;
	margin-left: auto;
	margin-right: auto;
	padding: 4px 11px;
	text-align: center;
	transition: all .3s ease-in-out;
	width: 100%;
}

.doform .radiofield input[type=radio]:checked +label, .radiofield label:hover {
	background-color: #eee;
	border-radius: 10px;
	color: #000;
}

.doform .radioblock label {
	border-bottom: 2px solid #333;
	font-size: 1em;
	margin-bottom: 1em;
	padding-bottom: 10px;
}

.doform .textradio .radiofield label {
	border: 1px solid #eee;
	border-radius: 10px;
	font-size: .9em;
	text-align: center;
}

.doform .formtext {
	background-color: #fff;
	border: 1px solid #eee;
	box-shadow: inset 0 0 2px #666;
	clear: both;
	color: #000;
	font-size: 18px;
	font-weight: 300;
	height: 30px;
	margin-bottom: 15px;
	padding: 0;
	width: 100%;
}

.doform .formselect {
	background-color: #fff;
	border: 1px solid #8694a1;
	clear: both;
	color: #000;
	font-size: 18px;
	font-weight: 300;
	height: 30px;
	margin-bottom: 15px;
	padding: 0;
	width: 100%;
}

.doform .forminfo {
	color: #900;
	display: block;
	font-size: 1.2em;
	padding-bottom: 15px;
}

.doform textarea {
	background-color: #fff;
	border: 1px solid #ccc;
	clear: both;
	color: #000;
	font-size: 18px;
	margin-bottom: 20px;
	width: 100%;
}

.doform label {
	clear: both;
	display: block;
	font-size: 1em;
	margin-bottom: .5em;
	margin-right: 20px;
}

.doform label.formerror {
	color: #900;
}

.doform label span {
	color: #414550;
}

.doform input[type=text]:focus, .doform input[type=text]:hover, .doform textarea:focus, .doform textarea:hover, .doform input[type=text]:focus, .doform input[type=text]:hover, .doform textarea:focus, .doform textarea:hover {
	background-color: #fff;
}

.doform input[type=submit] {
	background-color: #000;
	border: none;
	color: #fff;
	font-size: 1.2em;
	margin-bottom: 10px;
	padding: 8px;
	text-transform: uppercase;
	transition: all .3s ease-in-out;
}

.doform input[type=submit]:hover {
	background-color: #fff;
	color: #000;
}
