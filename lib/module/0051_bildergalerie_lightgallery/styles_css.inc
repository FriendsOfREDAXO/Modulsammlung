/**
* ---------------------------------------------------------------------------------
* CONTENT - LightGalery Effekte
* ---------------------------------------------------------------------------------
*/

/* Individual effects */

/*---------------*/
/***** Effektcode 0 *****/
/*---------------*/

figure.effect--0 img {
width: -webkit-calc(100% + 50px);
width: calc(100% + 50px);
opacity: 0.7;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-40px,0, 0);
transform: translate3d(-40px,0,0);
}

figure.effect--0 figcaption {
top: auto;
bottom: 0;
height: 50%;
text-align: left;
}

figure.effect--0 h2,
figure.effect--0 p {
-webkit-transform: translate3d(0,40px,0);
transform: translate3d(0,40px,0);
}

figure.effect--0 h2 {
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
}

figure.effect--0 p {
color: rgba(255,255,255,0.6);
opacity: 0;
-webkit-transition: opacity 0.2s, -webkit-transform 0.35s;
transition: opacity 0.2s, transform 0.35s;
}

figure.effect--0:hover img,
figure.effect--0:hover p {
opacity: 1;
}

figure.effect--0:hover img,
figure.effect--0:hover h2,
figure.effect--0:hover p {
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--0:hover p {
-webkit-transition-delay: 0.05s;
transition-delay: 0.05s;
-webkit-transition-duration: 0.35s;
transition-duration: 0.35s;
}

/*---------------*/
/***** Effektcode 1 *****/
/*---------------*/

figure.effect--1 figcaption::before {
position: absolute;
top: 0;
left: 0;
width: 100%;
height: 100%;
background: -webkit-linear-gradient(top, rgba(72,76,97,0) 0%, rgba(72,76,97,0.8) 75%);
background: linear-gradient(to bottom, rgba(72,76,97,0) 0%, rgba(72,76,97,0.8) 75%);
content: '';
opacity: 0;
-webkit-transform: translate3d(0,50%,0);
transform: translate3d(0,50%,0);
}

figure.effect--1 h2 {
position: absolute;
top: 50%;
left: 0;
width: 100%;
color: #484c61;
-webkit-transition: -webkit-transform 0.35s, color 0.35s;
transition: transform 0.35s, color 0.35s;
-webkit-transform: translate3d(0,-50%,0);
transform: translate3d(0,-50%,0);
}

figure.effect--1 figcaption::before,
figure.effect--1 p {
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
}

figure.effect--1 p {
position: absolute;
bottom: 0;
left: 0;
padding: 2em;
width: 100%;
opacity: 0;
-webkit-transform: translate3d(0,10px,0);
transform: translate3d(0,10px,0);
}

figure.effect--1:hover h2 {
color: #fff;
-webkit-transform: translate3d(0,-50%,0) translate3d(0,-40px,0);
transform: translate3d(0,-50%,0) translate3d(0,-40px,0);
}

figure.effect--1:hover figcaption::before ,
figure.effect--1:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}


/*---------------*/
/***** Effektcode 2 *****/
/*---------------*/

figure.effect--2 {
background: #4a3753;
}

figure.effect--2 img {
opacity: 0.9;
-webkit-transition: opacity 0.35s;
transition: opacity 0.35s;
}

figure.effect--2:hover img {
opacity: 0.5;
}

figure.effect--2 figcaption::before {
position: absolute;
bottom: 0;
left: 0;
width: 100%;
height: 10px;
background: #fff;
content: '';
-webkit-transform: translate3d(0,10px,0);
transform: translate3d(0,10px,0);
}

figure.effect--2 h2 {
position: absolute;
bottom: 0;
left: 0;
padding: 1em 1.5em;
width: 100%;
text-align: left;
-webkit-transform: translate3d(0,-30px,0);
transform: translate3d(0,-30px,0);
}

figure.effect--2 h2 i {
font-style: normal;
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(0,-30px,0);
transform: translate3d(0,-30px,0);
}

figure.effect--2 figcaption::before,
figure.effect--2 h2 {
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
}

figure.effect--2:hover figcaption::before,
figure.effect--2:hover h2,
figure.effect--2:hover h2 i {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

/*---------------*/
/***** Effektcode 3 *****/
/*---------------*/

figure.effect--3 {
background: #18a367;
}

figure.effect--3 img {
min-width: 100%;
height: -webkit-calc(100% + 40px);
height: calc(100% + 40px);
}

figure.effect--3 figcaption {
padding: 3em;
}

figure.effect--3 figcaption::before,
figure.effect--3 figcaption::after {
position: absolute;
content: '';
opacity: 0;
}

figure.effect--3 figcaption::before {
top: 50px;
right: 30px;
bottom: 50px;
left: 30px;
border-top: 1px solid #fff;
border-bottom: 1px solid #fff;
-webkit-transform: scale(0,1);
transform: scale(0,1);
-webkit-transform-origin: 0 0;
transform-origin: 0 0;
}

figure.effect--3 figcaption::after {
top: 30px;
right: 50px;
bottom: 30px;
left: 50px;
border-right: 1px solid #fff;
border-left: 1px solid #fff;
-webkit-transform: scale(1,0);
transform: scale(1,0);
-webkit-transform-origin: 100% 0;
transform-origin: 100% 0;
}

figure.effect--3 h2 {
padding-top: 26%;
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
}

figure.effect--3 p {
padding: 0.5em 2em;
text-transform: none;
opacity: 0;
-webkit-transform: translate3d(0,-10px,0);
transform: translate3d(0,-10px,0);
}

figure.effect--3 img,
figure.effect--3 h2 {
-webkit-transform: translate3d(0,-30px,0);
transform: translate3d(0,-30px,0);
}

figure.effect--3 img,
figure.effect--3 figcaption::before,
figure.effect--3 figcaption::after,
figure.effect--3 p {
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
}

figure.effect--3:hover img {
opacity: 0.7;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--3:hover figcaption::before,
figure.effect--3:hover figcaption::after {
opacity: 1;
-webkit-transform: scale(1);
transform: scale(1);
}

figure.effect--3:hover h2,
figure.effect--3:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--3:hover figcaption::after,
figure.effect--3:hover h2,
figure.effect--3:hover p,
figure.effect--3:hover img {
-webkit-transition-delay: 0.15s;
transition-delay: 0.15s;
}

/*---------------*/
/***** Effektcode 4 *****/
/*---------------*/

figure.effect--4 figcaption {
top: auto;
bottom: 0;
padding: 1em;
height: 3.75em;
background: #fff;
color: #3c4a50;
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(0,100%,0);
transform: translate3d(0,100%,0);
}

figure.effect--4 h2 {
float: left;
}

figure.effect--4 figcaption > span {
float: right;
}

figure.effect--4 p {
position: absolute;
bottom: 8em;
padding: 2em;
color: #fff;
text-transform: none;
font-size: 90%;
opacity: 0;
-webkit-transition: opacity 0.35s;
transition: opacity 0.35s;
}

figure.effect--4 h2,
figure.effect--4 figcaption > span {
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(0,200%,0);
transform: translate3d(0,200%,0);
}

figure.effect--4 figcaption > span::before {
display: inline-block;
padding: 8px 10px;
font-family: 'feathericons';
speak: none;
-webkit-font-smoothing: antialiased;
-moz-osx-font-smoothing: grayscale;
}

.icon-eye::before {
content: '\e000';
}

.icon-paper-clip::before {
content: '\e001';
}

.icon-heart::before {
content: '\e024';
}

figure.effect--4 h2 {
display: inline-block;
}

figure.effect--4:hover p {
opacity: 1;
}

figure.effect--4:hover figcaption,
figure.effect--4:hover h2,
figure.effect--4:hover figcaption > span {
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--4:hover h2 {
-webkit-transition-delay: 0.05s;
transition-delay: 0.05s;
}

figure.effect--4:hover figcaption > span:nth-child(4) {
-webkit-transition-delay: 0.1s;
transition-delay: 0.1s;
}

figure.effect--4:hover figcaption > span:nth-child(3) {
-webkit-transition-delay: 0.15s;
transition-delay: 0.15s;
}

figure.effect--4:hover figcaption > span:nth-child(2) {
-webkit-transition-delay: 0.2s;
transition-delay: 0.2s;
}

/*---------------*/
/***** Effektcode 5 *****/
/*---------------*/

figure.effect--5 {
background: -webkit-linear-gradient(45deg, #22682a 0%, #9b4a1b 40%, #3a342a 100%);
background: linear-gradient(45deg, #22682a 0%,#9b4a1b 40%,#3a342a 100%);
}

figure.effect--5 img {
opacity: 0.9;
-webkit-transition: opacity 0.35s;
transition: opacity 0.35s;
}

figure.effect--5 figcaption {
padding: 3em;
background-color: rgba(58,52,42,0.7);
-webkit-transition: background-color 0.35s;
transition: background-color 0.35s;
}

figure.effect--5 figcaption::before {
position: absolute;
top: 30px;
right: 30px;
bottom: 30px;
left: 30px;
border: 1px solid #fff;
content: '';
}

figure.effect--5 h2 {
margin: 20% 0 10px 0;
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(0,100%,0);
transform: translate3d(0,100%,0);
}

figure.effect--5 figcaption::before,
figure.effect--5 p {
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: scale(0);
transform: scale(0);
}

figure.effect--5:hover h2 {
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--5:hover figcaption::before,
figure.effect--5:hover p {
opacity: 1;
-webkit-transform: scale(1);
transform: scale(1);
}

figure.effect--5:hover figcaption {
background-color: rgba(58,52,42,0);
}

figure.effect--5:hover img {
opacity: 0.4;
}

/*---------------*/
/***** Effektcode 6 *****/
/*---------------*/

figure.effect--6 figcaption {
text-align: right;
}

figure.effect--6 h2,
figure.effect--6 p {
position: absolute;
right: 30px;
left: 30px;
padding: 10px 0;
}


figure.effect--6 p {
bottom: 30px;
line-height: 1.5;
-webkit-transform: translate3d(0,100%,0);
transform: translate3d(0,100%,0);
}

figure.effect--6 h2 {
top: 30px;
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(0,20px,0);
transform: translate3d(0,20px,0);
}

figure.effect--6:hover h2 {
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--6 h2::after {
position: absolute;
top: 100%;
left: 0;
width: 100%;
height: 4px;
background: #fff;
content: '';
-webkit-transform: translate3d(0,40px,0);
transform: translate3d(0,40px,0);
}

figure.effect--6 h2::after,
figure.effect--6 p {
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
}

figure.effect--6:hover h2::after,
figure.effect--6:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

/*---------------*/
/***** Effektcode 7 *****/
/*---------------*/

figure.effect--7 {
background-color: #17819c;
}

figure.effect--7 img {
opacity: 0.7;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: scale(1.15);
transform: scale(1.15);
}

figure.effect--7:hover img {
opacity: 0.5;
-webkit-transform: scale(1);
transform: scale(1);
}

figure.effect--7 h2 {
margin-top: 20%;
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(0,20px,0);
transform: translate3d(0,20px,0);
}

figure.effect--7 p {
margin: 1em 0 0;
padding: 3em;
border: 1px solid #fff;
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(0,20px,0) scale(1.1);
transform: translate3d(0,20px,0) scale(1.1);
}

figure.effect--7:hover h2 {
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--7:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0) scale(1);
transform: translate3d(0,0,0) scale(1);
}

/*---------------*/
/***** Effektcode 8 *****/
/*---------------*/

figure.effect--8 {
background: -webkit-linear-gradient(45deg, #ff89e9 0%, #05abe0 100%);
background: linear-gradient(45deg, #ff89e9 0%,#05abe0 100%);
}

figure.effect--8 img {
width: -webkit-calc(100% + 60px);
width: calc(100% + 60px);
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-50px,0,0);
transform: translate3d(-50px,0,0);
}

figure.effect--8 figcaption::before {
position: absolute;
top: 30px;
right: 30px;
bottom: 30px;
left: 30px;
border: 1px solid #fff;
content: '';
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-20px,0,0);
transform: translate3d(-20px,0,0);
}

figure.effect--8 figcaption {
padding: 3em;
text-align: left;
}

figure.effect--8 h2 {
padding: 30% 0 10px 0;
}

figure.effect--8 p {
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-10px,0,0);
transform: translate3d(-10px,0,0);
}

figure.effect--8:hover img {
opacity: 0.7;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--8:hover figcaption::before,
figure.effect--8:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

/*---------------*/
/***** Effektcode 9 *****/
/*---------------*/

figure.effect--9 {
background: #9e5406;
}

figure.effect--9 img {
opacity: 0.7;
-webkit-transition: opacity 0.35s;
transition: opacity 0.35s;
}

figure.effect--9:hover img {
opacity: 0.4;
}

figure.effect--9 figcaption::before,
figure.effect--9 figcaption::after {
position: absolute;
top: 30px;
right: 30px;
bottom: 30px;
left: 30px;
content: '';
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
}

figure.effect--9 figcaption::before {
border-top: 1px solid #fff;
border-bottom: 1px solid #fff;
-webkit-transform: scale(0,1);
transform: scale(0,1);
}

figure.effect--9 figcaption::after {
border-right: 1px solid #fff;
border-left: 1px solid #fff;
-webkit-transform: scale(1,0);
transform: scale(1,0);
}

figure.effect--9 h2 {
padding-top: 30%;
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(0,-20px,0);
transform: translate3d(0,-20px,0);
}

figure.effect--9 p {
padding: 20px 2.5em;
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(0,20px,0);
transform: translate3d(0,20px,0);
}

figure.effect--9:hover figcaption::before,
figure.effect--9:hover figcaption::after {
opacity: 1;
-webkit-transform: scale(1);
transform: scale(1);
}

figure.effect--9:hover h2,
figure.effect--9:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

/*---------------*/
/***** Effektcode 10 *****/
/*---------------*/

figure.effect--10 {
-webkit-perspective: 1000px;
perspective: 1000px;
}

figure.effect--10 img {
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(0,0,300px);
transform: translate3d(0,0,300px);
}

figure.effect--10:hover img {
opacity: 0.6;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--10 figcaption::before,
figure.effect--10 figcaption::after {
position: absolute;
top: 50%;
left: 50%;
width: 80%;
height: 1px;
background: #fff;
content: '';
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-50%,-50%,0);
transform: translate3d(-50%,-50%,0);
}

figure.effect--10:hover figcaption::before {
opacity: 0.5;
-webkit-transform: translate3d(-50%,-50%,0) rotate(45deg);
transform: translate3d(-50%,-50%,0) rotate(45deg);
}

figure.effect--10:hover figcaption::after {
opacity: 0.5;
-webkit-transform: translate3d(-50%,-50%,0) rotate(-45deg);
transform: translate3d(-50%,-50%,0) rotate(-45deg);
}

figure.effect--10 h2,
figure.effect--10 p {
position: absolute;
top: 50%;
left: 0;
width: 100%;
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
}

figure.effect--10 h2 {
-webkit-transform: translate3d(0,-50%,0) translate3d(0,-150%,0);
transform: translate3d(0,-50%,0) translate3d(0,-150%,0);
}

figure.effect--10 p {
padding: 0.25em 2em;
-webkit-transform: translate3d(0,-50%,0) translate3d(0,150%,0);
transform: translate3d(0,-50%,0) translate3d(0,150%,0);
}

figure.effect--10:hover h2 {
-webkit-transform: translate3d(0,-50%,0) translate3d(0,-100%,0);
transform: translate3d(0,-50%,0) translate3d(0,-100%,0);
}

figure.effect--10:hover p {
-webkit-transform: translate3d(0,-50%,0) translate3d(0,100%,0);
transform: translate3d(0,-50%,0) translate3d(0,100%,0);
}


/*---------------*/
/***** Effektcode 11 *****/
/*---------------*/

figure.effect--11 {
background: -webkit-linear-gradient(top, rgba(37,141,200,1) 0%, rgba(104,60,19,1) 100%);
background: linear-gradient(to bottom, rgba(37,141,200,1) 0%,rgba(104,60,19,1) 100%);
}

figure.effect--11 img {
-webkit-transition: opacity 0.35s;
transition: opacity 0.35s;
}

figure.effect--11:hover img {
opacity: 0.4;
}

figure.effect--11 figcaption::after {
position: absolute;
right: 30px;
bottom: 30px;
left: 30px;
height: -webkit-calc(50% - 30px);
height: calc(50% - 30px);
border: 7px solid #fff;
content: '';
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(0,-100%,0);
transform: translate3d(0,-100%,0);
}

figure.effect--11:hover figcaption::after {
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--11 figcaption {
padding: 3em;
text-align: left;
}

figure.effect--11 p {
position: absolute;
right: 60px;
bottom: 60px;
left: 60px;
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(0,-100px,0);
transform: translate3d(0,-100px,0);
}

figure.effect--11:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

/*---------------*/
/***** Effektcode 12 *****/
/*---------------*/

figure.effect--12 {
background: #42b078;
}

figure.effect--12 img {
width: -webkit-calc(100% + 20px);
width: calc(100% + 20px);
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-10px,0,0);
transform: translate3d(-10px,0,0);
-webkit-backface-visibility: hidden;
backface-visibility: hidden;
}

figure.effect--12:hover img {
opacity: 0.4;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--12 figcaption {
text-align: left;
}

figure.effect--12 h2 {
position: relative;
overflow: hidden;
padding: 0.5em 0;
}

figure.effect--12 h2::after {
position: absolute;
bottom: 0;
left: 0;
width: 100%;
height: 3px;
background: #fff;
content: '';
-webkit-transition: -webkit-transform 0.35s;
transition: transform 0.35s;
-webkit-transform: translate3d(-100%,0,0);
transform: translate3d(-100%,0,0);
}

figure.effect--12:hover h2::after {
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}

figure.effect--12 p {
padding: 1em 0;
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(100%,0,0);
transform: translate3d(100%,0,0);
}

figure.effect--12:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}



/*---------------*/
/***** Effektcode 13 *****/
/*---------------*/

figure.effect--13 img {
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: scale(1.12);
transform: scale(1.12);
}

figure.effect--13:hover img {
opacity: 0.5;
-webkit-transform: scale(1);
transform: scale(1);
}

figure.effect--13 figcaption {
padding: 3em;
}

figure.effect--13 figcaption::before {
position: absolute;
top: 30px;
right: 30px;
bottom: 30px;
left: 30px;
border: 1px solid #fff;
content: '';
-webkit-transform: scale(1.1);
transform: scale(1.1);
}

figure.effect--13 figcaption::before,
figure.effect--13 p {
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
}

figure.effect--13 h2 {
padding: 20% 0 20px 0;
}

figure.effect--13 p {
margin: 0 auto;
max-width: 200px;
-webkit-transform: scale(1.5);
transform: scale(1.5);
}

figure.effect--13:hover figcaption::before,
figure.effect--13:hover p {
opacity: 1;
-webkit-transform: scale(1);
transform: scale(1);
}

/*---------------*/
/***** Effektcode 14 *****/
/*---------------*/

figure.effect--14 {
background: #2e5d5a;
}

figure.effect--14 img {
width: -webkit-calc(100% + 60px);
width: calc(100% + 60px);
opacity: 1;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-30px,0,0) scale(1.12);
transform: translate3d(-30px,0,0) scale(1.12);
-webkit-backface-visibility: hidden;
backface-visibility: hidden;
}

figure.effect--14:hover img {
opacity: 0.5;
-webkit-transform: translate3d(0,0,0) scale(1);
transform: translate3d(0,0,0) scale(1);
}

figure.effect--14 h2 {
position: absolute;
right: 0;
bottom: 0;
padding: 1em 1.2em;
}

figure.effect--14 p {
padding: 0 10px 0 0;
width: 50%;
border-right: 1px solid #fff;
text-align: right;
opacity: 0;
-webkit-transition: opacity 0.35s, -webkit-transform 0.35s;
transition: opacity 0.35s, transform 0.35s;
-webkit-transform: translate3d(-40px,0,0);
transform: translate3d(-40px,0,0);
}

figure.effect--14:hover p {
opacity: 1;
-webkit-transform: translate3d(0,0,0);
transform: translate3d(0,0,0);
}