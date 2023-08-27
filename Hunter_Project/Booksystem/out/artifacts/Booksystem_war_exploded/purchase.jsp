<!DOCTYPE html>
<%@ page contentType="text/html; charset=gb2312"%>
<html>

<head>
    <%--    <meta charset="GB2312" />--%>
    <title>ͼ�����-�ɹ�ϵͳ</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="./bootstrap.css">
    <link rel="stylesheet" href="./bootstrap-theme.css">
    <link rel="stylesheet" href="./bootstrap-admin-theme.css">
    <link rel="stylesheet" href="./index.css" />
</head>

<body>

<!-- �ж��Ƿ��Ѿ���¼ -->
<div class="head">
    <img class="img" src="../img/title-yellow1.png"></img>
    <div class="userName">
        <p>�ɹ���¼</p>
    </div>
    <div class="daohang">
        <ul>
            <li style="margin-left: 100px;">
                <a href="login.jsp">�鼮��Ϣ����</a>
            </li>
            <li>
                <a href="purchase.jsp">�鼮��������</a>
            </li>
            <li>
                <a href="distribute.jsp">�鼮�ַ���¼</a>
            </li>
            <li>
                <a href="nowork.jsp">�������</a>
            </li>

            <li class="dropdown">
                <a href="nowork.jsp" class="" role="button" data-hover="dropdown">�ҵ�</a>
                <ul class="dropdown-menu">
                    <li><a href="#updateinfo" data-toggle="modal">��������</a></li>
                    <li><a href="#updatepwd" data-toggle="modal">�޸�����</a></li>
                    <li><a href="nowork.jsp">�˳�</a></li>
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
                <div class="title">�� ��</div>
                <div class="context">���޹���</div>
            </div>
            <div class="gongGao">
                <div class="title">�� �� �� ��</div>
                <div class="context">
                    <a href="https://www.csdn.net/">��CSDN</a>
                    <a href="https://github.com/">��GitHub</a>
                    <a href="https://stackoverflow.com/">��stackoverflow</a>
                    <a href="https://www.bilibili.com/">��bilibili</a>
                </div>
            </div>
            <div class="gongGao" style="height:400px;">
                <div class="title">��������Ϣ</div>
                <div class="context">
                    <div style="font-size:14px; width: 100%;  height: 400px;margin-bottom: 20px;">
                        <div style="padding: 5px;  color: black">
                            <label style="font-size:15px;font-weight: normal;">������</label><br />
                            <label style="font-size:15px;font-weight: normal;">��һ��</label><br />
                            <label style="font-size:15px;font-weight: normal;">��Զ��</label><br />
                            <label style="font-size:15px;font-weight: normal;">��˼��</label><br />
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
                                        <div class="text-muted bootstrap-admin-box-title">��ѯ</div>
                                    </div>
                                    <div class="bootstrap-admin-no-table-panel-content bootstrap-admin-panel-content collapse in">
                                        <form class="form-horizontal" action="#" method="get">
                                            <input type="hidden" name="tip" value="1">
                                            <div class="col-lg-7 form-group">
                                                <label class="col-lg-4 control-label" >�鼮���</label>
                                                <div class="col-lg-8">
                                                    <input class="form-control" id="bookName" name="name" type="text" value="">
                                                    <label class="control-label"  style="display: none;"></label>
                                                </div>
                                            </div>
                                            <div class="col-lg-3 form-group">

                                                <button onclick="search()" class="btn btn-primary" id="btn_query" onclick="">��ѯ</button>
                                            </div>
                                            <div class="col-lg-3 form-group">

                                                <button  type="button" class="btn btn-primary" id="btn_add" data-toggle="modal"
                                                         data-target="#addModal">��Ӽ�¼
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
                                        <th>ͼ���</th>
                                        <th>������</th>
                                        <th>����</th>
                                        <th>��������</th>

                                    </tr>
                                    </thead>


                                    <!---�ڴ˲�����Ϣ-->

                                    <tbody>
                                    <tr>
                                        <td>ͼ���1</td>
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
                        alert("����б༭")
                    }
                    ///���ͼ��
                    function addBooks(){
                        alert("����������鼮")
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
                        con = confirm("�Ƿ�ɾ��?ɾ���󲻿ɻָ�");
                        if (con == true) {
                            alert("��ɾ������ˢ�²鿴");
                        }
                    }
                </script>
            </div>

        </div>
    </div>

</div>

<div class="foot"><label class="lable">��Ҳ���е��ߵ�</label></div>



<!-------------------------��������ģ����------------------------------------->

<form class="form-horizontal" method="get" action="#">   <!--��֤��ʽˮƽ������-->
    <!-- ģ̬��Modal�� -->
    <div class="modal fade" id="updateinfo" tabindex="-1" role="dialog" aria-labelledby="ModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" id="ModalLabel">
                        ��������
                    </h4>
                </div>

                <div class="modal-body">

                    <!--����-->
                    <input type="hidden" name="tip" value="2">
                    <input type="hidden" name="url" value="admin/admin_books">
                    <div class="form-group">
                        <label  class="col-sm-3 control-label">��ʵ����</label>
                        <div class="col-sm-7">
                            <input readonly="true" type="text" class="form-control" id="name" name="name" placeholder="������������ʵ����"
                                   value='admin'>
                            <label class="control-label" for="name" style="display: none"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">�ֻ���</label>
                        <div class="col-sm-7">
                            <input readonly="true" type="text" class="form-control" id="phone" name="phone" placeholder="�����������ֻ���"
                                   value='11111'>
                            <label class="control-label" for="phone" style="display: none"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label  class="col-sm-3 control-label">����</label>
                        <div class="col-sm-7">
                            <input readonly="true" type="text" class="form-control" id="email" name="email" placeholder="��������������"
                                   value='admin@qq.com'>
                            <label class="control-label" for="email" style="display: none"></label>
                        </div>
                    </div>

                    <!--����-->


                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">�ر�
                    </button>
                    <button onclick="edit()" class="btn btn-primary">
                        �޸�
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!-------------------------------------------------------------->

<!-------------------------------------------------------------->

<form class="form-horizontal" method="get" action="#">   <!--��֤��ʽˮƽ������-->
    <!-- ģ̬��Modal�� -->
    <div class="modal fade" id="updatepwd" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" >
                        �޸�����
                    </h4>
                </div>
                <div class="modal-body">

                    <!--����-->
                    <input type="hidden" name="tip" value="1">
                    <input type="hidden" name="url" value="admin/admin_books">
                    <div class="form-group">
                        <label  class="col-sm-3 control-label">ԭ����</label>
                        <div class="col-sm-7">
                            <input type="password" class="form-control" name="password" id="oldPwd"
                                   placeholder="������ԭ����">
                            <label class="control-label" for="oldPwd" style="display: none"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">������</label>
                        <div class="col-sm-7">
                            <input type="password" class="form-control" name="password2" id="newPwd"
                                   placeholder="������������">
                            <label class="control-label" for="newPwd" style="display: none"></label>
                        </div>
                    </div>

                    <!--����-->
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">�ر�
                    </button>
                    <button type="submit" class="btn btn-primary">
                        �޸�
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!-------------------------------------------------------------->

<!-------------------------------------------------------------->

<!-- �޸�ģ̬��Modal�� -->
<form class="form-horizontal" method="get" action="#">   <!--��֤��ʽˮƽ������-->
    <div class="modal fade" id="updateModal" tabindex="-1" role="dialog" aria-labelledby="updateModalLabel"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" id="updateModalLabel">
                        �޸�ͼ����Ϣ
                    </h4>
                </div>
                <div class="modal-body">

                    <!---------------------��-------------------->

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">ͼ���</label>
                        <div class="col-sm-7">
                            <input type="hidden" id="updateBookId" name="updatebid">
                            <input type="text" class="form-control" id="updateISBN" name="card" placeholder="���������">
                            <label class="control-label" for="updateISBN" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label  class="col-sm-3 control-label">ͼ������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updateBookName" name="name"
                                   placeholder="������ͼ������">
                            <label class="control-label" for="updateBookName" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">ͼ������</label>
                        <div class="col-sm-7">
                            <select class="form-control" id="updateBookType" name="type"
                                    onPropertyChange="showValue(this.value)">
                                <option value="-1">��ѡ��</option>
                                <option value="1">ͼ������1</option>
                                <option value="1">ͼ������2</option>
                                <option value="1">ͼ������3</option>
                            </select>
                            <label class="control-label" for="updateBookType" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label  class="col-sm-3 control-label">��������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updateAutho" name="autho"
                                   placeholder="��������������">
                            <label class="control-label" for="updateAutho" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label class="col-sm-3 control-label">������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updatePress" name="press"
                                   placeholder="�����������">
                            <label class="control-label" for="updatePress" style="display: none;"></label>
                        </div>
                    </div>
                    <div class="form-group">
                        <label class="col-sm-3 control-label">������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="updateNum" name="num" placeholder="������������">
                            <label class="control-label" for="updatePress" style="display: none;"></label>
                        </div>
                    </div>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">�ر�
                    </button>
                    <button onclick="edit()" class="btn btn-primary">
                        �޸�
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!-------------------------------------------------------------->


<!--------------------------------------��ӵ�ģ����------------------------>
<form class="form-horizontal" method="get" action="#">   <!--��֤��ʽˮƽ������-->
    <!-- ģ̬��Modal�� -->
    <div class="modal fade" id="addModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">
                        &times;
                    </button>
                    <h4 class="modal-title" id="myModalLabel">
                        �����ͼ��
                    </h4>
                </div>
                <div class="modal-body">

                    <!---------------------��-------------------->

                    <div class="form-group">
                        <label class="col-sm-3 control-label">ͼ���</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addISBN" required="required" name="card"
                                   placeholder="���������">
                            <label class="control-label" for="addISBN" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-3 control-label">ͼ������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addBookName" required="required" name="name"
                                   placeholder="������ͼ������">
                            <label class="control-label" for="addBookName" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-3 control-label">ͼ������</label>
                        <div class="col-sm-7">
                            <select class="form-control" id="addBookType" name="type">
                                <option value="�޷���">��ѡ��</option>
                                <option value="1">ͼ������1</option>
                                <option value="1">ͼ������2</option>
                                <option value="1">ͼ������3</option>
                            </select>
                            <label class="control-label" for="addBookType" style="display: none;"></label>
                        </div>
                    </div>

                    <div class="form-group">
                        <label class="col-sm-3 control-label">��������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addAutho" required="required" name="autho"
                                   placeholder="��������������">
                            <label class="control-label" for="addAutho" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label class="col-sm-3 control-label">������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addPress" required="required" name="press"
                                   placeholder="�����������">
                            <label class="control-label" for="addPress" style="display: none;"></label>
                        </div>
                    </div>


                    <div class="form-group">
                        <label class="col-sm-3 control-label">������</label>
                        <div class="col-sm-7">
                            <input type="text" class="form-control" id="addNum" required="required" name="num"
                                   placeholder="������ͼ��������">
                            <label class="control-label" for="addNum" style="display: none;"></label>
                        </div>
                    </div>


                    <!---------------------��-------------------->
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">�ر�
                    </button>
                    <button onclick="addBooks()" class="btn btn-primary">
                        ���
                    </button>
                </div>
            </div><!-- /.modal-content -->
        </div><!-- /.modal -->
    </div>

</form>
<!--------------------------------------��ӵ�ģ����------------------------>


</body>



</html>