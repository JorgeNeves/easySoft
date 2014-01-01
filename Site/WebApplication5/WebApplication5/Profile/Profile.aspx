<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Profile.aspx.cs" Inherits="WebApplication5.Profile.Profile" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
        .auto-style1 {
            width: 357px;
        }
        .auto-style2 {
            width: 380px;
        }
        .auto-style3 {
            width: 357px;
            height: 309px;
        }
        .auto-style4 {
            width: 380px;
            height: 309px;
        }
        .auto-style5 {
            width: 273px;
        }
        .newStyle1 {
            font-family: "Trebuchet MS", "Lucida Sans Unicode", "Lucida Grande", "Lucida Sans", Arial, sans-serif;
            font-size: x-large;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" runat="server">
    <p>
        <table style="width:100%;">
            <tr>
                <td class="auto-style5">&nbsp;</td>
                <td class="auto-style5">
                    <asp:LinkButton ID="LinkButton3" runat="server" CssClass="contact" OnClick="LinkButton3_Click">Pagina Perfil</asp:LinkButton>
                </td>
                <td><asp:LinkButton ID="LinkButton1" runat="server" OnClick="LinkButton1_Click">Amigos</asp:LinkButton>
                </td>
                <td>
                <asp:LinkButton ID="LinkButton2" runat="server" OnClick="LinkButton2_Click">Pontos</asp:LinkButton>
                </td>
            </tr>
        </table>
    </p>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <span class="newStyle1">Perfil </span>    <br />
    <table style="width:100%;">
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
            <td class="auto-style4">&nbsp;<br />
            </td>
        </tr>
        <tr>
            <td class="auto-style1">
                <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Editar Perfil" />
            </td>
            <td class="auto-style2">&nbsp;</td>
        </tr>
        <tr>
            <td class="auto-style1">&nbsp;</td>
            <td class="auto-style2">&nbsp;</td>
        </tr>
    </table>
    <br />
    <br />
</asp:Content>
