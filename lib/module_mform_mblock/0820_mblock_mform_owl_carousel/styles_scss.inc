// CSS zur Positionierung des Textes auf dem Slider

.carousel-caption {
    top: 5%;
    left: 5%;
    right: 5%;
    bottom: 5%;
    padding-bottom: 0;
    text-shadow: none;

    .left-top {
        width: 33.3%;
        position: absolute;
        left: 0;
        top: 0;
    }

    .center-top {
        width: 33.3%;
        position: absolute;
        left: 33.3%;
        top: 0;
    }

    .right-top {
        width: 33.3%;
        position: absolute;
        left: 66.6%;
        top: 0;
    }

    .left-middle {
        width: 33.3%;
        position: absolute;
        left: 0;
        top: 33.3%;
    }

    .center-middle {
        width: 33.3%;
        position: absolute;
        left: 33.3%;
        top: 33.3%;
    }

    .right-middle {
        width: 33.3%;
        position: absolute;
        left: 66.6%;
        top: 33.3%;
    }

    .left-bottom {
        width: 33.3%;
        position: absolute;
        left: 0;
        top: 66.6;
    }

    .center-bottom {
        width: 33.3%;
        position: absolute;
        left: 33.3%;
        top: 66.6%;
    }

    .right-bottom {
        width: 33.3%;
        position: absolute;
        left: 66.6%;
        top: 66.6%;
    }
}


// CSS für die Positionierung der Dot-Navigation

.owl-dots {
    text-align: center;
    -webkit-tap-highlight-color: transparent;
    position: absolute;
    width: 100%;
    margin-top: -50px;

    .owl-dot {
        display: inline-block;
        zoom: 1;

        span {
            width: 12px;
            height: 12px;
            margin: 5px;
            background: #000;
            display: block;
            -webkit-backface-visibility: visible;
            transition: opacity 200ms ease;
            border-radius: 30px;
        }

        &.active,
        &:hover {
            span {
                border: 2px solid #000;
                background: $gray;
            }
        }
    }
}