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
            width: 2px;
        }
        .auto-style8 {
            width: 2px;
            height: 49px;
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
                    <asp:Label ID="lblcloudusers" runat="server" Text="Tag Cloud das tags de todos os utilizadores:" Width="292px"></asp:Label>
                </td>
                <td class="auto-style4">
                    <asp:Label ID="lbltagutilizadores" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style8">
                    <asp:Label ID="lbltagsrelacoes" runat="server" Text="Tag Cloud das Tags de todas as relações:" Width="299px"></asp:Label>
                </td>
                <td class="auto-style5">
                    <asp:Label ID="lbltagrelacoes" runat="server"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style8">
                    <asp:Label ID="lbldimensão" runat="server" Text="Dimensão da Rede:" Width="290px"></asp:Label>
                </td>
                <td class="auto-style5">
                    <asp:Label ID="lbldimrede" runat="server"></asp:Label>
                </td>
            </tr>
            </table>
    </p>
    <p>
        <asp:Label ID="Label3" runat="server" Font-Bold="True" Text="LeaderBoard"></asp:Label>
    </p>
    <asp:GridView ID="GridView1" runat="server" HorizontalAlign="Center">
    </asp:GridView>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;</p>
    <p>
    </p>
</asp:Content>
