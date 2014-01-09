﻿<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="EditProfile.aspx.cs" Inherits="WebApplication5.Profile.EditProfile" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
        .auto-style1 {
            width: 244px;
        }
        .auto-style2 {
            width: 244px;
            height: 31px;
        }
        .auto-style3 {
            height: 31px;
        }
        .auto-style4 {
            width: 239px;
        }
        .auto-style5 {
            height: 31px;
            width: 239px;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="FeaturedContent" runat="server">
</asp:Content>
<asp:Content ID="Content3" ContentPlaceHolderID="MainContent" runat="server">
    <table style="width:100%;">
        <tr>
            <td class="auto-style1">Primeiro Nome</td>
            <td>
                <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            </td>
            <td class="auto-style4">Password Antiga</td>
            <td>
                <asp:TextBox ID="TextBox7" runat="server" TextMode="Password"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style1">Ultimo Nome</td>
            <td>
                <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            </td>
            <td class="auto-style4">Nova Password</td>
            <td>
                <asp:TextBox ID="TextBox8" runat="server" TextMode="Password"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style1">Pais</td>
            <td>
                <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
            </td>
            <td class="auto-style4">Reescreve Nova Password</td>
            <td>
                <asp:TextBox ID="TextBox9" runat="server" TextMode="Password"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Mail</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
            </td>
            <td class="auto-style5"></td>
            <td class="auto-style3">
                <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Alterar Password" />
            </td>
        </tr>
        <tr>
            <td class="auto-style2">Facebook</td>
            <td class="auto-style3">
                <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
            </td>
            <td class="auto-style5"></td>
            <td class="auto-style3">
                <asp:Label ID="Label1" runat="server" ForeColor="#33CC33" Text="Alterada com sucesso" Visible="False"></asp:Label>
                <br />
                <asp:Label ID="Label2" runat="server" ForeColor="Red" Text="Erro ao alterar password" Visible="False"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style1">LinkedIn</td>
            <td>
                <asp:TextBox ID="TextBox6" runat="server"></asp:TextBox>
            </td>
            <td class="auto-style4">&nbsp;</td>
            <td>&nbsp;</td>
        </tr>
        <tr>
            <td class="auto-style1">Estado de Humor</td>
            <td>
                <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="SqlDataSource1" DataTextField="Sentimento" DataValueField="Sentimento">
                </asp:DropDownList>
                <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:DefaultConnection %>" SelectCommand="SELECT [Sentimento] FROM [EstadoDeHumors]"></asp:SqlDataSource>
            </td>
            <td class="auto-style4">&nbsp;</td>
            <td>&nbsp;</td>
        </tr>
        <tr>
            <td class="auto-style1">&nbsp;</td>
            <td>
                <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Atualizar" />
            </td>
            <td class="auto-style4">&nbsp;</td>
            <td>&nbsp;</td>
        </tr>
        <tr>
            <td class="auto-style1">Avatar </td>
            <td>
                <asp:FileUpload ID="FileUpload1" runat="server" Width="364px" />
            </td>
            <td class="auto-style4">&nbsp;</td>
            <td>&nbsp;</td>
        </tr>
        <tr>
            <td class="auto-style1">&nbsp;</td>
            <td>
                <asp:Button ID="Button3" runat="server" Text="Upload" OnClick="Button3_Click" />
            </td>
            <td class="auto-style4">
                <asp:Label ID="Label3" runat="server" ForeColor="#33CC33" Text="Upload com sucesso" Visible="False"></asp:Label>
                <br />
                <asp:Label ID="Label4" runat="server" ForeColor="Red" Text="Erro no upload" Visible="False"></asp:Label>
            </td>
            <td>&nbsp;</td>
        </tr>
    </table>
</asp:Content>