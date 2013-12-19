<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Profile.aspx.cs" Inherits="WebApplication2.Profile.Profile" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 131px;
        }
        .auto-style2 {
            width: 318px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <table style="width: 100%; height: 320px;">
            <tr>
                <td class="auto-style1">
                    <asp:Image ID="Image1" runat="server" Height="161px" Width="174px" />
                </td>
                <td class="auto-style2">Humor:</td>
                <td>Amigos</td>
            </tr>
            <tr>
                <td class="auto-style1">Nome
                    <asp:Label ID="Label1" runat="server"></asp:Label>
                </td>
                <td class="auto-style2">
                    <asp:Label ID="Label2" runat="server"></asp:Label>
                </td>
                <td>Facebook
                    <asp:Label ID="Label5" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Idade </td>
                <td class="auto-style2">
                    <asp:Label ID="Label3" runat="server"></asp:Label>
                </td>
                <td>LinkedIn
                    <asp:Label ID="Label6" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Mail</td>
                <td class="auto-style2">
                    <asp:Label ID="Label4" runat="server"></asp:Label>
                </td>
                <td>Pais
                    <asp:Label ID="Label7" runat="server"></asp:Label>
                </td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>
