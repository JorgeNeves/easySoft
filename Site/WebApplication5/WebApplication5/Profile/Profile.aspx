﻿<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Profile.aspx.cs" Inherits="WebApplication5.Profile.Profile" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
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
                    &nbsp;</td>
                <td>&nbsp;</td>
                <td>
                    &nbsp;</td>
            </tr>
        </table>
    </p>
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <span class="newStyle1">Perfil&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span>    <br />
    <table style="width:100%;">
        <tr>
            <td class="auto-style6">
            </td>
            <td class="auto-style7">
                <h6>Tens
                    <asp:Label ID="Label10" runat="server" ForeColor="Blue"></asp:Label>
                    <asp:LinkButton ID="LinkButton1" runat="server" OnClick="LinkButton1_Click" PostBackUrl="~/Profile/Friends.aspx">Amigos</asp:LinkButton>
                </h6>
            </td>
            <td class="auto-style7">&nbsp;</td>
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
            <td class="auto-style4" colspan="2">&nbsp;<br />
                <asp:Button ID="Button2" runat="server" Height="36px" OnClick="Button2_Click" Text="Pedidos Pendentes (0)" />
                <br />
                <asp:Label ID="Label9" runat="server" ForeColor="#33CC33" Text="Não tem pedidos de momento" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style1">
                <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Editar Perfil" />
            </td>
            <td class="auto-style2" colspan="2">&nbsp;</td>
        </tr>
        <tr>
            <td class="auto-style1">&nbsp;</td>
            <td class="auto-style2" colspan="2">&nbsp;</td>
        </tr>
    </table>
    <br />
    <br />
</asp:Content>
