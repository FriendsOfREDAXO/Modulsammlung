#sitemap {
  ul {
    li {
      a {
        margin: 0 0 5px 0;
        padding: 2px 15px 2px 10px;
        font-size: 1.3em;
        color: #22365B;
        text-decoration: none;
        &:before {
          font-family: 'FontAwesome';
          margin: 0 5px 0 0;
          font-size: 1em;
          font-weight: bold;
          content: "\f105";
        }
        &:hover {
          color: #000;
        }
      }
      &:before {
        display: none;
      }
      ul {
        li {
          padding-left: 20px;
          &:first-child {
            padding-top: 10px;
          }
          &:last-child {
            margin-bottom: 10px;
          }
          a {
            color: #000;
            font-size: 1em;
            text-decoration: none;
            &:before {
              font-size: 20px;
            }
          }
        }
      }
    }
  }

  a.seositemapedit {
    font-size: 12px;
    color: #000;
    &:before {
      color: #000;
      font-size: 12px;
    }
    &:hover {
      color: #f00;
      &:before {
        color: #f00;
      }
    }
  }

  span {
      display: inline-block;
      font-size: 12px;
      margin-left: 20px;
      strong {
        font-weight: bold;
      }
  }


  .warning strong  {
    font-family: verdana;
    font-size: 10px;
    color: #f00;
  }
}

