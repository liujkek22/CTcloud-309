<%--
  Created by IntelliJ IDEA.
  User: 13741
  Date: 2022/12/18
  Time: 16:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <link rel="stylesheet" href="http://at.alicdn.com/t/font_1786038_m62pqneyrzf.css">
  <title>高校书籍管理系统</title>
  <style>
    * {
      margin: 0;
      padding: 0;
    }

    html {
      height: 100%;
    }

    .body-item {
      height: 100%;
      font-family: JetBrains Mono Medium;
      display: flex;
      align-items: center;
      justify-content: center;
      /*background-color: #0e92b3;*/
      background:  url("../img/background.png") no-repeat;
      background-size: 100% 100%;
    }

    .form-wrapper {
      width: 300px;
      background-color: rgba(41, 45, 62, .8);
      color: #fff;
      border-radius: 2px;
      padding: 50px;
    }

    .form-wrapper .header {
      text-align: center;
      font-size: 35px;
      text-transform: uppercase;
      line-height: 100px;
    }

    .form-wrapper .input-wrapper input {
      background-color: rgb(41, 45, 62);
      border: 0;
      width: 100%;
      text-align: center;
      font-size: 15px;
      color: #fff;
      outline: none;
    }

    .form-wrapper .input-wrapper input::placeholder {
      text-transform: uppercase;
    }

    .form-wrapper .input-wrapper .border-wrapper {
      background-image: linear-gradient(to right, #e8198b, #0eb4dd);
      width: 100%;
      height: 50px;
      margin-bottom: 20px;
      border-radius: 30px;
      display: flex;
      align-items: center;
      justify-content: center;
    }

    .form-wrapper .input-wrapper .border-wrapper .border-item {
      height: calc(100% - 4px);
      width: calc(100% - 4px);
      border-radius: 30px;
    }

    .form-wrapper .action {
      margin: auto auto;
      display: flex;
      justify-content: center;
    }

    .form-wrapper .action {
      width: 60%;
      text-transform: uppercase;
      border: 2px solid #0e92b3;
      text-align: center;
      line-height: 50px;
      border-radius: 30px;
      cursor: pointer;
    }
    .formclass{
      margin: auto auto;
    }
    .btn {
      width: 60%;
      margin-left: 65px;
      text-transform: uppercase;
      border: 2px solid #0e92b3;
      text-align: center;
      line-height: 50px;
      border-radius: 30px;
      cursor: pointer;
      font-size: 22px;
      color: #fff;
      background: linear-gradient(120deg, #84fab0 0%, #8fd3f4 100%);
    }

    .form-wrapper .action {
      background-image: linear-gradient(120deg, #84fab0 0%, #8fd3f4 100%);
    }
    .btn:hover {
      background-image: linear-gradient(120deg, #84fab0 0%, #8fd3f4 100%);
    }
    .form-wrapper .icon-wrapper {
      text-align: center;
      width: 60%;
      margin: 0 auto;
      margin-top: 20px;
      border-top: 1px dashed rgb(146, 146, 146);
      padding: 20px;
    }

    .form-wrapper .icon-wrapper i {
      font-size: 20px;
      color: rgb(187, 187, 187);
      cursor: pointer;
      border: 1px solid #fff;
      padding: 5px;
      border-radius: 20px;
    }

    .form-wrapper .icon-wrapper i:hover {
      background-color: #0e92b3;
    }
  </style>
</head>

<body class="body-item">
<div class="form-wrapper">
  <div class="header">
    高校书籍管理系统
  </div>
  <form method="post" action="index-servlet" class="formclass" >
  <div class="input-wrapper">
    <div class="border-wrapper">
      <input type="text" name="username" placeholder="username" class="border-item" autocomplete="off">
    </div>
    <div class="border-wrapper">
      <input type="password" name="password" placeholder="password" class="border-item" autocomplete="off">
    </div>
  </div>

      <button class="btn">登 陆</button>
    </form>

  <div class="icon-wrapper">
    <i class="iconfont icon-weixin"></i>
    <i class="iconfont icon-qq"></i>
    <i class="iconfont icon-git"></i>
  </div>
</div>
</body>

</html>