<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Consulta.aspx.cs" Inherits="WebApplication5.Profile.Consulta" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
        .auto-style4 {
            height: 23px;
            width: 251px;
        }
        .auto-style5 {
            width: 251px;
            height: 49px;
        }
        .auto-style6 {
            width: 253px;
        }
        .auto-style7 {
            height: 23px;
            width: 111px;
        }
        .auto-style8 {
            width: 111px;
            height: 49px;
        }
        .auto-style9 {
            width: 122px;
        }
        .auto-style10 {
            width: 104px;
        }
        </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" runat="server">
    <p>
        <br />
    </p>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <p>
        <asp:Label ID="Label1" runat="server" Text="Available Statistics" Font-Bold="True"></asp:Label>
        <br />
        <table style="width:100%;">
            <tr>
                <td class="auto-style7">
        <asp:Button ID="btnuserstags" runat="server" Text="Tag cloud das tags de todos os utilizadores" Width="315px" OnClick="btnuserstags_Click"  />
                </td>
                <td class="auto-style4">
        <asp:Button ID="btnleaderamigos" runat="server" Text="Leader Board de Amigos" Width="295px" OnClick="btnleaderamigos_Click" />
                </td>
            </tr>
            <tr>
                <td class="auto-style8">
        <asp:Button ID="Button4" runat="server" Text="Tag cloud das tags de todas as relações" Width="315px" OnClick="Button4_Click1"  />
                </td>
                <td class="auto-style5">
        <asp:Button ID="Button6" runat="server" Text="Dimensão da Rede" Width="292px" />
                </td>
            </tr>
            </table>
    </p>
    <p>
        <asp:Label ID="Label2" runat="server" Text="Logged User Only" Font-Bold="True"></asp:Label>
    </p>
    <p>
        <table style="width:100%;">
            <tr>
                <td class="auto-style6">&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style6">
        <asp:Button ID="btnusertag" runat="server"  Text="Consultar suas Tags de utilizador" Width="295px" OnClick="btnusertag_Click" />
                </td>
                <td>
        <asp:Button ID="btnusertagsrelacoes" runat="server" Text="Consultar suas Tags das relações" OnClick="btnusertagsrelacoes_Click" Width="347px"  />
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style6">
        <asp:Button ID="Button7" runat="server" Text="Sugestões de Amigos" Width="288px" />
                </td>
                <td>
        <asp:Button ID="Button8" runat="server" Text="Tamanho da Sua Rede Social" Width="347px" />
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </p>
    <p>
        <asp:Label ID="lbltipotag" runat="server"></asp:Label>
    </p>
    <p>
        <asp:Label ID="lbltag" runat="server"></asp:Label>
    </p>
    <p>
        <table style="width:100%;">
            <tr>
                <td class="auto-style9">&nbsp;</td>
                <td class="auto-style10">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style9">
                    <asp:GridView ID="GridView1" runat="server" Visible="False">
                    </asp:GridView>
                </td>
                <td class="auto-style10">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style9">&nbsp;</td>
                <td class="auto-style10">&nbsp;</td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </p>
    <p>
    </p>
</asp:Content>
