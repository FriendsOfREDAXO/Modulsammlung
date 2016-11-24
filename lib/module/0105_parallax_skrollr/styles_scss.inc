.prallax{
	display: inline-block;
	width: 100%;
	font-family: sans-serif;
	color: #fff;
	position: relative;
	margin: 0 auto;
	padding: 60px 0 60px 0;
	background-position: center center;
	-webkit-background-size: cover;
	-moz-background-size: cover;
	-o-background-size: cover;
	background-size: cover;
	text-align: center;
	.parallaxcontent {
		position: absolute;
		top: 50%;
		left: 50%;
		max-width: 90%;
		min-width: 60%;
		padding: 25px 100px 25px 100px;
		transform: translate(-50%,-50%);
        background: rgba(0, 0, 0, 0.45);
 		-moz-border-radius: 3px;
		-webkit-border-radius: 3px;
		-khtml-border-radius: 3px;
		border-radius: 3px;
		.parallax_ueberschrift {
			font-size: 2em;
			font-weight: 100;
			line-height: 1.2;
		}
		.parallax_text {
			padding-top: 1.5em;
			display: block;
			font-size: 1.2em;
			font-weight: 100;
			line-height: 1.3;
			a {
				color: #fff;
				border-bottom: 2px dotted #fff;
				&:hover {
					border-bottom: 2px solid #fff;					
				}
			}
		}
	}
}
