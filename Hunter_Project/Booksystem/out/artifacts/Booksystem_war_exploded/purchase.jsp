<!DOCTYPE html>
<%@ page contentType="text/html; charset=gb2312"%>
<html>

<head>
    <%--    <meta charset="GB2312" />--%>
    <title>图书管理-采购系统</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="./bootstrap.css">
    <link rel="stylesheet" href="./bootstrap-theme.css">
    <link rel="stylesheet" href="./bootstrap-admin-theme.css">
    <link rel="stylesheet" href="./index.css" />
</head>

<body>

<!-- 判断是否已经登录 -->
<div class="head">
    <img class="img" src="../img/title-yellow1.png"></img>
    <div class="userName">
        <p>采购记录</p>
    </div>
    <div class="daohang">
        <ul>
            <li style="margin-left: 100px;">
                <a href="login.jsp">书籍信息管理</a>
            </li>
            <li>
                <a href="purchase.jsp">书籍进购管理</a>
            </li>
            <li>
                <a href="distribute.jsp">书籍分发记录</a>
            </li>
            <li>
                <a href="nowork.jsp">公告管理</a>
            </li>

            <li class="dropdown">
                <a href="nowork.jsp" class="" role="button" data-hover="dropdown">我的</a>
                <ul class="dropdown-menu">
                    <li><a href="#updateinfo" data-toggle="modal">个人资料</a></li>
                    <li><a href="#updatepwd" data-toggle="modal">修改密码</a></li>
                    <li><a href="nowork.jsp">退出</a></li>
                </ul>
            </li>
        </ul>
    </div>
</div>
<div style="width: 100%;float: left;height: 310px;"></div>
<div class="body">
    <div class="content">
        <div class="left">
            <div class="gongGao">
                <div class="title">公 告</div>
                <div class="context">暂无公告</div>
            </div>
            <div class="gongGao">
                <div class="title">友 情 链 接</div>
                <div class="context">
                    <a href="https://www.csdn.net/">》CSDN</a>
                    <a href="https://github.com/">》GitHub</a>
                    <a href="https://stackoverflow.com/">》stackoverflow</a>
                    <a href="https://www.bilibili.com/">》bilibili</a>
                </div>
            </div>
            <div class="gongGao" style="height:400px;">
                <div class="title">开发者信息</div>
                <div class="context">
                    <div style="font-size:14px; width: 100%;  height: 400px;margin-bottom: 20px;">
                        <div style="padding: 5px;  color: black">
                            <label style="font-size:15px;font-weight: normal;">陈星宇</label><br />
                            <label style="font-size:15px;font-weight: normal;">白一卉</label><br />
                            <label style="font-size:15px;font-weight: normal;">毕远雯</label><br />
                            <label style="font-size:15px;font-weight: normal;">边思琦</label><br />
                        </div>
                        <img width="160px" style="position: relative;left: 50%;margin-left: -80px;" src="../img/ghz.jpg" />
                    </div>
                </div>
            </div>
        </div>
        <div class="right">

            <div class="container">
                <!-- left, vertical navbar & content -->
                <div class="row">

                    <!-- content -->
                    <div class="col-md-10">


                        <div class="row">
                            <div class="col-lg-12">
                                <div class="panel panel-default bootstrap-admin-no-table-panel">
                                    <div class="panel-heading">
                                        <div class="text-muted bootstrap-admin-box-title">查询</div>
                                    </div>
                                    <div class="bootstrap-admin-no-table-panel-content bootstrap-admin-panel-content collapse in">
                                        <form class="form-horizontal" action="#" method="get">
                                            <input type="hidden" name="tip" value="1">
                                            <div class="col-lg-7 form-group">
                                                <label class="col-lg-4 control-label" >书籍书号</label>
                                                <div class="col-lg-8">
                                                    <input class="form-control" id="bookName" name="name" type="text" value="">
                                                    <label class="control-label"  style="display: none;"></label>
                                                </div>
                                            </div>
                                            <div class="col-lg-3 form-group">

                                                <button onclick="search()" class="btn btn-primary" id="btn_query" onclick="">查询</button>
                                            </div>
                                            <div class="col-lg-3 form-group">

                                                <button  type="button" class="btn btn-primary" id="btn_add" data-toggle="modal"
                                                         data-target="#addModal">添加记录
                                                </button>
                                            </div>
                                        </form>
                                    </div>
                                </div>
                            </div>
                        </div>


                        <div class="row">
                            <div class="col-lg-12">
                                <table id="data_list" class="table table-hover table-bordered" cellspacing="0" width="100%">
                                    <thead>
                                    <tr>
                                        <th>图书号</th>
                                        <th>订购量</th>
                                        <th>日期</th>
                                        <th>到达数量</th>

                                    </tr>
                                    </thead>


                                    <!---在此插入信息-->

                                    <tbody>
                                    <tr>
                                        <td>图书号1</td>
                                        <td>0</td>
                                        <td>0-0-0</td>
                                        <td>0</td>
                                    </tr>

                                    </tbody>

                                </table>
                            </div>
                        </div>
                    </div>
                </div>
                <script type="text/javascript">

                    function edit(){
                        alert("请进行编辑")
                    }
                    ///添加图书
                    function addBooks(){
                        alert("请添加所需书籍")
                    }


                    function showInfo2(bid, card, type, name, autho, press, num) {
                        document.getElementById("updateISBN").value = card;
                        document.getElementById("updateBookName").value = name;
                        document.getElementById("updateAutho").value = autho;
                        document.getElementById("updatePress").value = press;
                        document.getElementById("updateBookType").value = type;
                        document.getElementById("updateNum").value = num;
                        document.getElementById("updateBookId").value = bid;
                    }

                    function deletebook(bid) {
                        con = confirm("是否删除?删除后不可恢复");
                        if (con == true) {
                            alert("已删除，请刷新查看");
                        }
                    }
                </script>
            </div>

        </div>
    </div>

</div>

<div class="foot"><label class="lable">我也是有底线的</label></div>



<!-------------------------个人资料模糊框------------------------------------->

<form class="form-horizontal" method="get" action="#">   <!--保证样式水平不混乱-->
    <!-- 模态框（Modal） -->
    <div class="modal fade" id="updateinfo" tabindex="-1" role="dialog" aria-labelledby="ModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" id="ModalLabel">
                        个人资料
                    </h4>
                </div>

                <div class="modal-body">

                    <!--正文-->
                    <input type="hidden" name="tip" value="2">
                    <input type="hidden" name="url" value="admin/admin_books">
                    <div class="form-group">
                        <label  class="col-sm-3 control-label">真实姓名</label>
                        <div class="col-sm-7">
                            <input readonly="true" type="text" class="form-control" id="name" name="name" placeholder="请输入您的真实姓名"
                                   value='admin'>
                            <label class="control-label" for="name" style="display: none"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">手机号</label>
                        <div class="col-sm-7">
                            <input readonly="true" type="text" class="form-control" id="phone" name="phone" placeholder="请输入您的手机号"
                                   value='11111'>
                            <label class="control-label" for="phone" style="display: none"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label  class="col-sm-3 control-label">邮箱</label>
                        <div class="col-sm-7">
                            <input readonly="true" type="text" class="form-control" id="email" name="email" placeholder="请输入您的邮箱"
                                   value='admin@qq.com'>
                            <label class="control-label" for="email" style="display: none"></label>
                        </div>
                    </div>

                    <!--正文-->


                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭
                    </button>
                    <button onclick="edit()" class="btn btn-primary">
                        修改
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!-------------------------------------------------------------->

<!-------------------------------------------------------------->

<form class="form-horizontal" method="get" action="#">   <!--保证样式水平不混乱-->
    <!-- 模态框（Modal） -->
    <div class="modal fade" id="updatepwd" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" >
                        修改密码
                    </h4>
                </div>
                <div class="modal-body">

                    <!--正文-->
                    <input type="hidden" name="tip" value="1">
                    <input type="hidden" name="url" value="admin/admin_books">
                    <div class="form-group">
                        <label  class="col-sm-3 control-label">原密码</label>
                        <div class="col-sm-7">
                            <input type="password" class="form-control" name="password" id="oldPwd"
                                   placeholder="请输入原密码">
                            <label class="control-label" for="oldPwd" style="display: none"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">新密码</label>
                        <div class="col-sm-7">
                            <input type="password" class="form-control" name="password2" id="newPwd"
                                   placeholder="请输入新密码">
                            <label class="control-label" for="newPwd" style="display: none"></label>
                        </div>
                    </div>

                    <!--正文-->
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭
                    </button>
                    <button type="submit" class="btn btn-primary">
                        修改
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!-------------------------------------------------------------->

<!-------------------------------------------------------------->

<!-- 修改模态框（Modal） -->
<form class="form-horizontal" method="get" action="#">   <!--保证样式水平不混乱-->
    <div class="modal fade" id="updateModal" tabindex="-1" role="dialog" aria-labelledby="updateModalLabel"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" id="updateModalLabel">
                        修改图书信息
                    </h4>
                </div>
                <div class="modal-body">

                    <!---------------------表单-------------------->

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">图书号</label>
                        <div class="col-sm-7">
                            <input type="hidden" id="updateBookId" name="updatebid">
                            <input type="text" class="form-control" id="updateISBN" name="card" placeholder="请输入书号">
                            <label class="control-label" for="updateISBN" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label  class="col-sm-3 control-label">图书名称</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updateBookName" name="name"
                                   placeholder="请输入图书名称">
                            <label class="control-label" for="updateBookName" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">图书类型</label>
                        <div class="col-sm-7">
                            <select class="form-control" id="updateBookType" name="type"
                                    onPropertyChange="showValue(this.value)">
                                <option value="-1">请选择</option>
                                <option value="1">图书类型1</option>
                                <option value="1">图书类型2</option>
                                <option value="1">图书类型3</option>
                            </select>
                            <label class="control-label" for="updateBookType" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">作者名称</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updateAutho" name="autho"
                                   placeholder="请输入作者名称">
                            <label class="control-label" for="updateAutho" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label class="col-sm-3 control-label">出版社</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updatePress" name="press"
                                   placeholder="请输入出版社">
                            <label class="control-label" for="updatePress" style="display: none;"></label>
                        </div>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-3 control-label">总数量</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updateNum" name="num" placeholder="请输入总数量">
                            <label class="control-label" for="updatePress" style="display: none;"></label>
                        </div>
                    </div>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭
                    </button>
                    <button onclick="edit()" class="btn btn-primary">
                        修改
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!-------------------------------------------------------------->


<!--------------------------------------添加的模糊框------------------------>
<form class="form-horizontal" method="get" action="#">   <!--保证样式水平不混乱-->
    <!-- 模态框（Modal） -->
    <div class="modal fade" id="addModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" id="myModalLabel">
                        添加新图书
                    </h4>
                </div>
                <div class="modal-body">

                    <!---------------------表单-------------------->

                    <div class="form-group">
                        <label class="col-sm-3 control-label">图书号</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addISBN" required="required" name="card"
                                   placeholder="请输入书号">
                            <label class="control-label" for="addISBN" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-3 control-label">图书名称</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addBookName" required="required" name="name"
                                   placeholder="请输入图书名称">
                            <label class="control-label" for="addBookName" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-3 control-label">图书类型</label>
                        <div class="col-sm-7">
                            <select class="form-control" id="addBookType" name="type">
                                <option value="无分类">请选择</option>
                                <option value="1">图书类型1</option>
                                <option value="1">图书类型2</option>
                                <option value="1">图书类型3</option>
                            </select>
                            <label class="control-label" for="addBookType" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-3 control-label">作者名称</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addAutho" required="required" name="autho"
                                   placeholder="请输入作者名称">
                            <label class="control-label" for="addAutho" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label class="col-sm-3 control-label">出版社</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addPress" required="required" name="press"
                                   placeholder="请输入出版社">
                            <label class="control-label" for="addPress" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label class="col-sm-3 control-label">总数量</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addNum" required="required" name="num"
                                   placeholder="请输入图书总数量">
                            <label class="control-label" for="addNum" style="display: none;"></label>
                        </div>
                    </div>


                    <!---------------------表单-------------------->
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">关闭
                    </button>
                    <button onclick="addBooks()" class="btn btn-primary">
                        添加
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!--------------------------------------添加的模糊框------------------------>


</body>



</html>