﻿//------------------------------------------------------------------------------
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
    using System.Data.Entity;
    using System.Data.Entity.Infrastructure;
    
    public partial class easysoftdbEntities : DbContext
    {
        public easysoftdbEntities()
            : base("name=easysoftdbEntities")
        {
        }
    
        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            throw new UnintentionalCodeFirstException();
        }
    
        public virtual DbSet<C__MigrationHistory> C__MigrationHistory { get; set; }
        public virtual DbSet<Applications> Applications { get; set; }
        public virtual DbSet<Downloads> Downloads { get; set; }
        public virtual DbSet<EstadoDeHumors> EstadoDeHumors { get; set; }
        public virtual DbSet<EstadoDeLigacaos> EstadoDeLigacaos { get; set; }
        public virtual DbSet<Ligacao_Tag> Ligacao_Tag { get; set; }
        public virtual DbSet<Ligacaos> Ligacaos { get; set; }
        public virtual DbSet<Memberships> Memberships { get; set; }
        public virtual DbSet<Profiles> Profiles { get; set; }
        public virtual DbSet<Roles> Roles { get; set; }
        public virtual DbSet<TagOriginals> TagOriginals { get; set; }
        public virtual DbSet<Tags> Tags { get; set; }
        public virtual DbSet<User_Tag> User_Tag { get; set; }
        public virtual DbSet<UserProfile> UserProfile { get; set; }
        public virtual DbSet<Users> Users { get; set; }
        public virtual DbSet<webpages_Membership> webpages_Membership { get; set; }
        public virtual DbSet<webpages_OAuthMembership> webpages_OAuthMembership { get; set; }
        public virtual DbSet<webpages_Roles> webpages_Roles { get; set; }
    }
}
