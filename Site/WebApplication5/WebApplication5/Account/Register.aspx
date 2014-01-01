<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Register.aspx.cs" Inherits="WebApplication5.Account.Register" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
        .auto-style2 {
            width: 298px;
        }
        .auto-style3 {
            width: 327px;
        }
        .auto-style4 {
            width: 298px;
            height: 54px;
        }
        .auto-style5 {
            width: 327px;
            height: 54px;
        }
        .auto-style6 {
            height: 54px;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" runat="server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <table style="width:100%;">
        <tr>
            <td class="auto-style2">Username</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox1" runat="server" ValidateRequestMode="Enabled" ViewStateMode="Enabled"></asp:TextBox>
            </td>
            <td>
                <asp:Label ID="Label1" runat="server" ForeColor="Red" Text="User already exist!" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Password</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </td>
            <td>
                <asp:Label ID="Label2" runat="server" ForeColor="Red" Text="* must be filled" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Repeat Password</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox3" runat="server" TextMode="Password"></asp:TextBox>
            </td>
            <td>
                <asp:Label ID="Label3" runat="server" ForeColor="Red" Text="* must be filled" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Mail</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox9" runat="server"></asp:TextBox>
            </td>
            <td>
                <asp:Label ID="Label9" runat="server" ForeColor="Red" Text="* email invalid" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">First Name</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
            </td>
            <td>
                <asp:Label ID="Label4" runat="server" ForeColor="Red" Text="* must be filled" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Last Name</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
            </td>
            <td>
                <asp:Label ID="Label5" runat="server" ForeColor="Red" Text="* must be filled" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Birthday</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox8" runat="server"></asp:TextBox>
            </td>
            <td>
                <asp:Label ID="Label6" runat="server" ForeColor="Red" Text="* must be filled" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Country</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox7" runat="server"></asp:TextBox>
            </td>
            <td>
                <asp:Label ID="Label7" runat="server" ForeColor="Red" Text="* must be filled" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style4"></td>
            <td class="auto-style5">
                <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Register" />
            </td>
            <td class="auto-style6">
                <asp:Label ID="Label8" runat="server" ForeColor="#00CC00" Text="Registration Successful" Visible="False"></asp:Label>
            </td>
        </tr>
    </table>
</asp:Content>
