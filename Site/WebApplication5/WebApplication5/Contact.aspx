<%@ Page Title="Contact" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Contact.aspx.cs" Inherits="WebApplication5.Contact" %>

<asp:Content runat="server" ID="BodyContent" ContentPlaceHolderID="MainContent">
    <hgroup class="title">
        <h1><%: Title %>.</h1>
        <h2>Contacts</h2>
    </hgroup>

    <section class="contact">
        <header>
            <h3>Email:</h3>
        </header>
        <p>
            <span class="label">Support:</span> <a href="mailto:antoniopfpeixoto@gmail">antoniopfpeixoto@gmail.com</a></p>
        <p>
            &nbsp;</p>
        <header>
            <h3>Address:</h3>
        </header>
        <p>
            DEI-Instituto Superior de Engenharia do Porto
        </p>
    </section>
</asp:Content>