<%@ Page Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="WebApplication2.Account.Login" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">

<body>
    
    <form id="form1" runat="server" >
    <div>
    
        <table style="width:100%;" >
            <tr>
                <td class="auto-style2">Login</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style2">Username</td>
                <td>
                    <asp:TextBox ID="UserTextBox" runat="server" ></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">Password</td>
                <td>
                    <asp:TextBox ID="PassTextBox" runat="server" TextMode="Password"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">
                    <asp:Button ID="SubmitButton" runat="server" OnClick="Button1_Click" Text="Login" />
                </td>
                <td>
                    <asp:Button ID="Button1" runat="server" OnClick="Button1_Click1" Text="Register" />
                </td>
            </tr>
            <tr>
                <td class="auto-style1" colspan="2">
                    <asp:Label ID="ErroLoginLabel" runat="server" ForeColor="Red" Text="Username and/or password is incorrect!" Visible="False"></asp:Label>
                </td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>
    </asp:Content>