<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Profile.aspx.cs" Inherits="WebApplication5.Profile.Profile" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
        .newStyle1 {
            font-family: "Trebuchet MS", "Lucida Sans Unicode", "Lucida Grande", "Lucida Sans", Arial, sans-serif;
            font-size: x-large;
        }
        .auto-style2 {
            width: 347px;
        }
        .auto-style3 {
            width: 336px;
        }
        
    
       body{
              font-family: 'lucida grande', tahoma, verdana, arial, sans-serif;
       }
       .contentArea{
              width:596px;
              margin:0 auto;
            height: 78px;
        }
       #inputSearch
       {
              width:581px;
              border:solid 1px #000;
              padding:3px;
       }
       #divResult
       {
              position:absolute;
              width:350px;
              display:none;
              margin-top:-1px;
              border:solid 1px #dedede;
              border-top:0px;
              overflow:hidden;
              border-bottom-right-radius: 6px;
              border-bottom-left-radius: 6px;
              -moz-border-bottom-right-radius: 6px;
              -moz-border-bottom-left-radius: 6px;
              box-shadow: 0px 0px 5px #999;
              border-width: 3px 1px 1px;
              border-style: solid;
              border-color: #333 #DEDEDE #DEDEDE;
              background-color: white;
       }
       .display_box
       {
              padding:px; border-top:solid 1px #dedede;
              font-size:12px; height:50px;
       }
       .display_box:hover
       {
              background:#3bb998;
              color:#FFFFFF;
              cursor:pointer;
       }
        .auto-style4 {
            width: 336px;
            height: 29px;
        }
        .auto-style5 {
            width: 347px;
            height: 29px;
        }
        .auto-style6 {
            width: 414px;
            height: 29px;
        }
        .auto-style7 {
            width: 414px;
        }
    </style>
    
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" runat="server">
    </asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <script type="text/javascript">
        
        $(function () {
            $(".search").keyup(function () {
                var inputSearch = $(this).val();
                var dataString = 'searchword=' + inputSearch;
                if (inputSearch != '') {
                    $.ajax({
                        type: "POST",
                        url: "Search.aspx",
                        data: dataString,
                        cache: false,
                        success: function (html) {
                            $("#divResult").html(html).show();
                        }
                    });
                } return false;
            });

            jQuery("#divResult").live("click", function (e) {
                var $clicked = $(e.target);
                window.location.replace("FriendProfile.aspx?nome=" + $clicked.find('.name').html());
                var $name = $clicked.find('.name').html();
                var decoded = $("<div/>").html($name).text();
                $('#inputSearch').val(decoded);
                
            });
            jQuery(document).live("click", function (e) {
                var $clicked = $(e.target);
                if (!$clicked.hasClass("search")) {
                    jQuery("#divResult").fadeOut();
                }
            });
            $('#inputSearch').click(function () {
                jQuery("#divResult").fadeIn();
            });
        });
    </script>
    <span class="newStyle1">Perfil&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span>    <br />
    <table style="width:100%;">
        <tr>
            <td class="auto-style4">
            </td>
            <td class="auto-style6">
                <h6>Tens
                    <asp:Label ID="Label10" runat="server" ForeColor="Blue"></asp:Label>
                    <asp:LinkButton ID="LinkButton1" runat="server" OnClick="LinkButton1_Click" PostBackUrl="~/Profile/Friends.aspx">Amigos</asp:LinkButton>
                </h6>
            </td>
            <td class="auto-style5">
                <h6>&nbsp;</h6>
            </td>
        </tr>
        <tr>
            <td class="auto-style3">
                <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Overline="False" Font-Strikeout="False"></asp:Label>
&nbsp;(<asp:Label ID="Label2" runat="server"></asp:Label>
                )<br />
                <asp:Image ID="Image1" runat="server" Height="135px" Width="130px" />
&nbsp;&nbsp;&nbsp;
                <br />
                Data de Nascimento :
                <asp:Label ID="Label3" runat="server"></asp:Label>
                <br />
                Estado de Humor
                : Está
                <asp:Label ID="Label4" runat="server"></asp:Label>
                <br />
                Mail
                :
                <asp:Label ID="Label5" runat="server"></asp:Label>
                <br />
                Facebook
                :
                <asp:Label ID="Label6" runat="server"></asp:Label>
                <br />
                LinkedIn
                :
                <asp:Label ID="Label7" runat="server"></asp:Label>
                <br />
                Pais
                :
                <asp:Label ID="Label8" runat="server"></asp:Label>
            </td>
            <td class="auto-style7">&nbsp;<br />
                <asp:Button ID="Button2" runat="server" Height="36px" OnClick="Button2_Click" Text="Pedidos Pendentes (0)" />
                <br />
                <asp:Label ID="Label9" runat="server" ForeColor="#33CC33" Text="Não tem pedidos de momento" Visible="False"></asp:Label>
            </td>
            <td class="auto-style2">
                <div class="contentArea">
                    <h6>Procura aqui por amigos</h6>
                <input type="text" class="search" id="inputSearch" name="inputSearch" autocomplete="on"/><br />
                    <br />
&nbsp;<br />
                <div id="divResult">
                    
                </div>
                </div>
        
            </td>
            <td>
                &nbsp;</td>
        </tr>
        <tr>
            <td class="auto-style3">
                <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Editar Perfil" />
            </td>
            <td class="auto-style7">
                <asp:Label ID="Label12" runat="server" Font-Bold="True" Text="UserTags"></asp:Label>
                <br />
                <asp:Label ID="lblusertags" runat="server" Text="Não tem UserTag's"></asp:Label>
                <br />
                <br />
                <asp:Label ID="Label11" runat="server" Font-Bold="True" Text="Tags das suas Relações"></asp:Label>
                <br />
                <asp:Label ID="lblreltags" runat="server" Text="Não tem TAGs de relações"></asp:Label>
            </td>
            <td class="auto-style2">
                <h6>
                    <asp:Label ID="Label13" runat="server" Text="Amigos que deves conhecer"></asp:Label>
                </h6>
                <p>
                    <asp:Label ID="amigosugeridos" runat="server" Text="Label"></asp:Label>
                </p>
            </td>
        </tr>
        <tr>
            <td class="auto-style3">&nbsp;</td>
            <td class="auto-style7">&nbsp;</td>
            <td class="auto-style2">&nbsp;</td>
        </tr>
    </table>
    <br />
    <br />
</asp:Content>
