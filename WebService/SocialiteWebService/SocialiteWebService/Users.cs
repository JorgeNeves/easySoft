//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace SocialiteWebService
{
    using System;
    using System.Collections.Generic;
    
    public partial class Users
    {
        public int UserID { get; set; }
        public string Nick { get; set; }
        public string Password { get; set; }
        public string Mail { get; set; }
        public string PrimeiroNome { get; set; }
        public string UltimoNome { get; set; }
        public string DataDeNascimento { get; set; }
        public string Pais { get; set; }
        public Nullable<int> EstadoDeHumorID { get; set; }
        public string AvatarUrl { get; set; }
        public string PerfilFacebook { get; set; }
        public string PerfilLinkedIn { get; set; }
    }
}
